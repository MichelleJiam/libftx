/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:43:11 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 19:46:49 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int		converter(t_format *data, va_list list, int *printcount)
{
	if (data->width == -1)
		widthsetter(data, list);
	if (data->precision == -1)
		data->precision = va_arg(list, int);
	if (data->type == 'c')
		return (conv_char(data, list, printcount));
	if (data->type == 's')
		return (conv_string(data, list, printcount));
	if (data->type == 'd' || data->type == 'i')
		return (conv_int(data, list, printcount));
	if (data->type == '%')
		return (conv_percent(data, printcount));
	if (data->type == 'n')
		return (conv_n(data, list, printcount));
	if (data->type == 'x' || data->type == 'X' || data->type == 'u' ||
		data->type == 'p')
		return (conv_hex(data, list, printcount));
	else
		return (-1);
}

void	flagchecker(const char **input, t_format *data)
{
	if (**input == '-')
		data->left = 1;
	else if (**input == '0')
		data->zero = 1;
	else if (**input == '+' || **input == ' ')
	{
		if (!(data->sp_plus) || data->sp_plus == ' ')
			data->sp_plus = **input;
		data->sign = 1;
	}
	else if (**input == '#')
		data->hash = 1;
	else if (**input == 39)
		data->group = 1;
	else if (**input == '*')
		data->width = -1;
	else if (ft_isdigit(**input))
		data->width = ft_atoi(*input);
	else if (**input == '.')
		precisionsetter(input, data);
	if (**input == 'h' || **input == 'l')
		sizesetter(input, data);
}

int		typefinder(const char **input)
{
	char	*types;

	types = "cspdiuxX%n";
	if (**input)
	{
		while (*types)
		{
			if (**input == *types)
				return (1);
			types++;
		}
	}
	return (0);
}

int		parser(const char **input, t_format *data, va_list list, int *printcount)
{
	while (**input && isvalid(input, data))
	{
		if (typefinder(input))
		{
			data->type = **input;
			return (converter(data, list, printcount));
		}
		flagchecker(input, data);
		if (data->width != 0 || data->precision != -2)
		{
			while (**input && ft_isdigit(*(*input + 1)))
				(*input)++;
		}
		(*input)++;
	}
	return (-1);
}
