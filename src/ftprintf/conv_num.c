/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_num.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 11:59:19 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 19:46:49 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static int		num_printer(t_format *data, char *str, intmax_t num, size_t len)
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
	if (data->sign)
		printer(data->sp_plus, 1, &printcount);
	if (!data->left && data->zero)
		printer('0', newlen - signedlen, &printcount);
	if ((data->left && data->precision > (int)len) || !data->left)
		printer('0', data->precision - len, &printcount);
	writer((num < 0 ? str + 1 : str), len, &printcount);
	if (data->left)
		printer(' ', newlen - signedlen, &printcount);
	return (printcount);
}

static intmax_t	vargtype(t_format *data, va_list list)
{
	intmax_t num;

	if (data->modifier == l)
		num = va_arg(list, long);
	else if (data->modifier == ll)
		num = va_arg(list, long long);
	else
		num = va_arg(list, int);
	if (data->modifier == h)
		num = (short)num;
	else if (data->modifier == hh)
		num = (char)num;
	return (num);
}

int				conv_int(t_format *data, va_list list, int *printcount)
{
	intmax_t	num;
	size_t		len;
	char		*str;

	num = vargtype(data, list);
	if (!data->precision && !num && !data->width && !data->sp_plus)
		return (0);
	str = p_itoa(num, data);
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (num < 0)
	{
		len--;
		data->sp_plus = '-';
		data->sign = 1;
	}
	if (data->precision != -2)
		data->zero = 0;
	if (num == 0 && data->precision == 0)
		len = 0;
	*printcount += num_printer(data, str, num, len);
	free(str);
	return (0);
}
