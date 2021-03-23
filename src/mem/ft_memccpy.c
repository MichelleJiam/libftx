/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 17:07:17 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 16:28:39 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* copies bytes from string src to string dst.  
If the character c (as converted to an unsigned char) occurs in the string src,
the copy stops and a pointer to the byte after the copy of c in the string dst
is returned.  Otherwise, n bytes are copied, and a NULL pointer is returned.
The source and destination strings should not overlap (undefined behaviour). */

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	i = 0;
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		if (src_ptr[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
