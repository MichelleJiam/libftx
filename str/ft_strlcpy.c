/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:18:41 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/05 11:44:39 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t c;

	c = 0;
	if (dst == 0)
		return (0);
	if (dstsize > 0)
	{
		while (c < dstsize - 1 && src[c])
		{
			dst[c] = src[c];
			c++;
		}
		dst[c] = '\0';
	}
	while (src[c] != '\0')
		c++;
	return (c);
}
