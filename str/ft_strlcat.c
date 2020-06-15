/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:00:22 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/05 11:44:51 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t d;
	size_t n;

	d = 0;
	n = 0;
	while (dst[d])
		d++;
	while (n < dstsize - d - 1 && src[n] && dstsize > d)
	{
		dst[d + n] = src[n];
		n++;
	}
	dst[d + n] = '\0';
	while (src[n] != '\0')
		n++;
	if (dstsize < d)
		return (n + dstsize);
	return (d + n);
}
