/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 15:35:35 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/05 11:45:44 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	i = 0;
	if (!dst && !src)
		return (0);
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
