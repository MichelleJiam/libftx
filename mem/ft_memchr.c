/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 20:43:44 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/12 17:25:53 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*p;
	int		i;

	i = 0;
	p = 0;
	while (n > 0)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			p = &((void *)s)[i];
			return (p);
		}
		i++;
		n--;
	}
	return (0);
}
