/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 12:35:56 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 22:20:46 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int	lenadjuster(t_format *format, size_t len)
{
	size_t	newlen;

	newlen = len;
	if (format->width != (int)len)
		newlen = format->width;
	if (format->precision != -2 && format->width < format->precision)
	{
		if (format->type == 's' && format->precision < (int)len)
			newlen = format->precision;
		else if (format->type != 's' && format->precision > (int)len)
			newlen = format->precision;
	}
	return (newlen);
}

void	format_initialiser(t_format *format)
{
	format->modifier = 0;
	format->left = 0;
	format->zero = 0;
	format->precision = -2;
	format->hash = 0;
	format->group = 0;
	format->sp_plus = 0;
	format->sign = 0;
	format->size = 0;
	format->width = 0;
}

int	ft_printf(const char *input, ...)
{
	va_list		list;
	t_format	format;
	int			printcount;

	printcount = 0;
	va_start(list, input);
	while (*input)
	{
		if (*input != '%')
			ftp_writer(input, 1, &printcount);
		else
		{
			format_initialiser(&format);
			input++;
			if (format_parser(&input, &format, list, &printcount) < 0)
				return (-1);
		}
		input++;
	}
	va_end(list);
	return (printcount);
}
