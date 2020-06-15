/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 17:07:17 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/05 11:46:06 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*p;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	p = &dst[i];
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (n > 0)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
		{
			i++;
			p = &dst[i];
			return (p);
		}
		i++;
		n--;
	}
	return (0);
}
