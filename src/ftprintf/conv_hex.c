/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_hex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:46:08 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 19:30:57 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static int		unum_printer(t_data *data, char *str, size_t len)
{
	int		printcount;
	size_t	signedlen;
	size_t	newlen;

	printcount = 0;
	if (data->precision == -2 || data->precision < (int)len)
		data->precision = (int)len;
	newlen = adjuster(data, len);
	if ((int)newlen < data->precision + data->sign)
		signedlen = newlen;
	else
		signedlen = data->precision + data->sign;
	if (!data->left && !data->zero)
		printer(' ', newlen - signedlen, &printcount);
	if (data->sign == 2)
		writer((data->type == 'X' ? "0X" : "0x"), 2, &printcount);
	if (!data->left && data->zero)
		printer('0', newlen - signedlen, &printcount);
	if ((data->left && data->precision > (int)len) || !data->left)
		printer('0', data->precision - len, &printcount);
	writer(str, len, &printcount);
	if (data->left)
		printer(' ', newlen - signedlen, &printcount);
	return (printcount);
}

static intmax_t	vargtype(t_data *data, va_list list)
{
	intmax_t num;

	if (data->modifier == l)
		num = va_arg(list, unsigned long);
	else if (data->modifier == ll || data->type == 'p')
		num = va_arg(list, unsigned long long);
	else
		num = va_arg(list, unsigned int);
	if (data->modifier == h)
		num = (unsigned short)num;
	else if (data->modifier == hh)
		num = (unsigned char)num;
	return (num);
}

int				conv_hex(t_data *data, va_list list, int *printcount)
{
	uintmax_t		unum;
	char			*str;
	size_t			len;
	unsigned int	base;

	unum = vargtype(data, list);
	if (!data->precision && !unum && !data->width && data->type != 'p')
		return (0);
	base = (data->type == 'u' ? 10 : 16);
	str = u_itoa(unum, data, base);
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (data->precision != -2)
		data->zero = 0;
	if (data->sp_plus == '+' || data->sp_plus == ' ')
		data->sign = 0;
	else if (data->type == 'p' || (data->hash && base == 16 && unum != 0))
		data->sign = 2;
	if (unum == 0 && data->precision == 0)
		len = 0;
	*printcount += unum_printer(data, str, len);
	free(str);
	return (0);
}

int				conv_n(t_data *data, va_list list, int *printcount)
{
	intmax_t	*n;
	int			*m;

	if (data->modifier == l)
		n = va_arg(list, long *);
	else if (data->modifier == ll)
		n = (intmax_t *)va_arg(list, long long *);
	else
	{
		m = va_arg(list, int *);
		*m = *printcount;
		return (*m);
	}
	if (data->modifier == h)
		n = (intmax_t *)(short int *)n;
	else if (data->modifier == hh)
		n = (intmax_t *)(char *)n;
	*n = *printcount;
	return (*n);
}
