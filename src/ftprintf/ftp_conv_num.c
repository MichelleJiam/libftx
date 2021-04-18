/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftp_conv_num.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/18 22:27:07 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 22:27:35 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static int	num_ftp_printer(t_format *format, char *str, intmax_t num,
	size_t len)
{
	int		printcount;
	size_t	signedlen;
	size_t	newlen;

	printcount = 0;
	if (format->precision == -2 || format->precision < (int)len)
		format->precision = (int)len;
	newlen = lenadjuster(format, len);
	if ((int)newlen < format->precision + format->sign)
		signedlen = newlen;
	else
		signedlen = format->precision + format->sign;
	if (!format->left && !format->zero)
		ftp_printer(' ', newlen - signedlen, &printcount);
	if (format->sign)
		ftp_printer(format->sp_plus, 1, &printcount);
	if (!format->left && format->zero)
		ftp_printer('0', newlen - signedlen, &printcount);
	if ((format->left && format->precision > (int)len) || !format->left)
		ftp_printer('0', format->precision - len, &printcount);
	ftp_writer((num < 0 ? str + 1 : str), len, &printcount);
	if (format->left)
		ftp_printer(' ', newlen - signedlen, &printcount);
	return (printcount);
}

static intmax_t	vargtype(t_format *format, va_list list)
{
	intmax_t	num;

	if (format->modifier == l)
		num = va_arg(list, long);
	else if (format->modifier == ll)
		num = va_arg(list, long long);
	else
		num = va_arg(list, int);
	if (format->modifier == h)
		num = (short)num;
	else if (format->modifier == hh)
		num = (char)num;
	return (num);
}

int	ftp_conv_num(t_format *format, va_list list, int *printcount)
{
	intmax_t	num;
	size_t		len;
	char		*str;

	num = vargtype(format, list);
	if (!format->precision && !num && !format->width && !format->sp_plus)
		return (0);
	str = ftp_signed_itoa(num, format);
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (num < 0)
	{
		len--;
		format->sp_plus = '-';
		format->sign = 1;
	}
	if (format->precision != -2)
		format->zero = 0;
	if (num == 0 && format->precision == 0)
		len = 0;
	*printcount += num_ftp_printer(format, str, num, len);
	free(str);
	return (0);
}
