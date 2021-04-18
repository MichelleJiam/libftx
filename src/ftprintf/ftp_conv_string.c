/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftp_conv_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/18 22:24:59 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 22:25:10 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int	ftp_conv_string(t_format *format, va_list list, int *printcount)
{
	size_t	len;
	size_t	newlen;
	char	*str;

	if (format->precision == 0 && !format->width)
		return (0);
	if (format->precision < 0)
		format->precision = -2;
	str = va_arg(list, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	newlen = lenadjuster(format, len);
	if (format->precision != -2 && format->precision < (int)len)
		len = format->precision;
	if (!format->left && newlen > len)
		ftp_printer(' ', newlen - len, printcount);
	ftp_writer(str, len, printcount);
	if (format->left && newlen > len)
		ftp_printer(' ', newlen - len, printcount);
	return (0);
}
