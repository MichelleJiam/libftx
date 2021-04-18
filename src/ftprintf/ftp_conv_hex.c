/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftp_conv_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/18 22:23:34 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 22:45:07 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static int	unum_ftp_printer(t_format *format, char *str, size_t len)
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
	if (format->sign == 2)
		ftp_writer((format->type == 'X' ? "0X" : "0x"), 2, &printcount);
	if (!format->left && format->zero)
		ftp_printer('0', newlen - signedlen, &printcount);
	if ((format->left && format->precision > (int)len) || !format->left)
		ftp_printer('0', format->precision - len, &printcount);
	ftp_writer(str, len, &printcount);
	if (format->left)
		ftp_printer(' ', newlen - signedlen, &printcount);
	return (printcount);
}

static intmax_t	vargtype(t_format *format, va_list list)
{
	intmax_t	num;

	if (format->modifier == l)
		num = va_arg(list, unsigned long);
	else if (format->modifier == ll || format->type == 'p')
		num = va_arg(list, unsigned long long);
	else
		num = va_arg(list, unsigned int);
	if (format->modifier == h)
		num = (unsigned short)num;
	else if (format->modifier == hh)
		num = (unsigned char)num;
	return (num);
}

static void	set_sign(t_format *format, uintmax_t unum, unsigned int base)
{
	if (format->sp_plus == '+' || format->sp_plus == ' ')
		format->sign = 0;
	else if (format->type == 'p' || (format->hash && base == 16 && unum != 0))
		format->sign = 2;
}

int	ftp_conv_hex(t_format *format, va_list list, int *printcount)
{
	uintmax_t		unum;
	char			*str;
	size_t			len;
	unsigned int	base;

	unum = vargtype(format, list);
	if (!format->precision && !unum && !format->width && format->type != 'p')
		return (0);
	if (format->type == 'u')
		base = 10;
	else
		base = 16;
	str = ftp_unsigned_itoa(unum, format, base);
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (format->precision != -2)
		format->zero = 0;
	set_sign(format, unum, base);
	if (unum == 0 && format->precision == 0)
		len = 0;
	*printcount += unum_ftp_printer(format, str, len);
	free(str);
	return (0);
}

int	ftp_conv_n(t_format *format, va_list list, int *printcount)
{
	intmax_t	*n;
	int			*m;

	if (format->modifier == l)
		n = va_arg(list, long *);
	else if (format->modifier == ll)
		n = (intmax_t *)va_arg(list, long long *);
	else
	{
		m = va_arg(list, int *);
		*m = *printcount;
		return (*m);
	}
	if (format->modifier == h)
		n = (intmax_t *)(short int *)n;
	else if (format->modifier == hh)
		n = (intmax_t *)(char *)n;
	*n = *printcount;
	return (*n);
}
