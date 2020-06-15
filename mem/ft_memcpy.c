/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 16:24:30 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/05 11:45:49 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		n--;
	}
	return (dst);
}
