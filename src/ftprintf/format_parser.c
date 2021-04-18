/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_parser.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/18 22:10:03 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 22:28:42 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int	converter(t_format *format, va_list list, int *printcount)
{
	if (format->width == -1)
		widthsetter(format, list);
	if (format->precision == -1)
		format->precision = va_arg(list, int);
	if (format->type == 'c')
		return (ftp_conv_char(format, list, printcount));
	if (format->type == 's')
		return (ftp_conv_string(format, list, printcount));
	if (format->type == 'd' || format->type == 'i')
		return (ftp_conv_num(format, list, printcount));
	if (format->type == '%')
		return (ftp_conv_percent(format, printcount));
	if (format->type == 'n')
		return (ftp_conv_n(format, list, printcount));
	if (format->type == 'x' || format->type == 'X' || format->type == 'u'
		|| format->type == 'p')
		return (ftp_conv_hex(format, list, printcount));
	else
		return (-1);
}

void	flagchecker(const char **input, t_format *format)
{
	if (**input == '-')
		format->left = 1;
	else if (**input == '0')
		format->zero = 1;
	else if (**input == '+' || **input == ' ')
	{
		if (!(format->sp_plus) || format->sp_plus == ' ')
			format->sp_plus = **input;
		format->sign = 1;
	}
	else if (**input == '#')
		format->hash = 1;
	else if (**input == 39)
		format->group = 1;
	else if (**input == '*')
		format->width = -1;
	else if (ft_isdigit(**input))
		format->width = ft_atoi(*input);
	else if (**input == '.')
		precisionsetter(input, format);
	if (**input == 'h' || **input == 'l')
		sizesetter(input, format);
}

int	typefinder(const char **input)
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

static int	isvalid(const char **input, t_format *format)
{
	if (!**input)
	{
		format->type = 0;
		return (0);
	}
	return (1);
}

int	format_parser(const char **input, t_format *format,
	va_list list, int *printcount)
{
	while (**input && isvalid(input, format))
	{
		if (typefinder(input))
		{
			format->type = **input;
			return (converter(format, list, printcount));
		}
		flagchecker(input, format);
		if (format->width != 0 || format->precision != -2)
		{
			while (**input && ft_isdigit(*(*input + 1)))
				(*input)++;
		}
		(*input)++;
	}
	return (-1);
}
