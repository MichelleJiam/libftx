/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:00:22 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:48:17 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Appends string src to the end of dst. 
Function will append at most dstsize - strlen(dst) - 1 characters.  
It will then NUL-terminate, unless dstsize is 0 or the original dst string 
was longer than dstsize (in practice this should not happen as it means that 
either dstsize is incorrect or that dst is not a proper string). */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	n;

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
