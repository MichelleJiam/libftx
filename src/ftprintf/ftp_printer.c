/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftp_printer.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/18 22:23:22 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 22:23:24 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	ftp_writer(const char *ptr, size_t len, int *printcount)
{
	write(1, ptr, len);
	*printcount += len;
}

void	ftp_printer(const char c, size_t len, int *printcount)
{
	size_t	i;

	i = 0;
	while (len && i < len)
	{
		ftp_writer(&c, 1, printcount);
		i++;
	}
}
