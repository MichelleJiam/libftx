/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 15:35:35 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:39:09 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* copies len bytes from string src to string dst.
The two strings may overlap; the copy is always done in a 
non-destructive manner. Returns original value of dst. */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (len > 0)
	{
		if (src < dst)
		{
			i = len - 1;
			if (((unsigned char *)dst)[i] != ((unsigned char *)src)[i])
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
		else
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
		len--;
	}
	return (dst);
}
