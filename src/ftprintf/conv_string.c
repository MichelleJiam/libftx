/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_string.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:41:07 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 19:30:57 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int		conv_string(t_data *data, va_list list, int *printcount)
{
	size_t	len;
	size_t	newlen;
	char	*str;

	if (data->precision == 0 && !data->width)
		return (0);
	if (data->precision < 0)
		data->precision = -2;
	str = va_arg(list, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	newlen = adjuster(data, len);
	if (data->precision != -2 && data->precision < (int)len)
		len = data->precision;
	if (!data->left && newlen > len)
		printer(' ', newlen - len, printcount);
	writer(str, len, printcount);
	if (data->left && newlen > len)
		printer(' ', newlen - len, printcount);
	return (0);
}
