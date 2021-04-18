/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_char.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:36:05 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 19:46:49 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int		conv_percent(t_format *data, int *printcount)
{
	char	filler;

	filler = ((!data->left) & data->zero ? '0' : ' ');
	if (data->width > 1 && !data->left)
		printer(filler, data->width - 1, printcount);
	printer('%', 1, printcount);
	if (data->width > 1 && data->left)
		printer(' ', data->width - 1, printcount);
	return (0);
}

int		conv_char(t_format *data, va_list list, int *printcount)
{
	int		c;
	char	filler;

	filler = ((!data->left) & data->zero ? '0' : ' ');
	c = va_arg(list, int);
	if (data->width > 1 && !data->left)
		printer(filler, data->width - 1, printcount);
	printer((char)c, 1, printcount);
	if (data->width > 1 && data->left)
		printer(' ', data->width - 1, printcount);
	return (0);
}
