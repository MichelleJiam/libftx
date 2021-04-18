/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftp_conv_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/18 22:20:59 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 22:23:11 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int	ftp_conv_percent(t_format *format, int *printcount)
{
	char	filler;

	if ((!format->left) & format->zero)
		filler = '0';
	else
		filler = ' ';
	if (format->width > 1 && !format->left)
		ftp_printer(filler, format->width - 1, printcount);
	ftp_printer('%', 1, printcount);
	if (format->width > 1 && format->left)
		ftp_printer(' ', format->width - 1, printcount);
	return (0);
}

int	ftp_conv_char(t_format *format, va_list list, int *printcount)
{
	int		c;
	char	filler;

	if ((!format->left) & format->zero)
		filler = '0';
	else
		filler = ' ';
	c = va_arg(list, int);
	if (format->width > 1 && !format->left)
		ftp_printer(filler, format->width - 1, printcount);
	ftp_printer((char)c, 1, printcount);
	if (format->width > 1 && format->left)
		ftp_printer(' ', format->width - 1, printcount);
	return (0);
}
