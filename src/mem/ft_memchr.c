/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 20:43:44 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 22:53:34 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* locates first occurrence of c (converted to an unsigned char) in string s.
Returns a pointer to the byte located, or NULL if no such byte exists within 
n bytes. */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_ptr;

	i = 0;
	s_ptr = (unsigned char *)s;
	while (i < n)
	{
		if (s_ptr[i] == (unsigned char)c)
			return (s_ptr + i);
		i++;
	}
	return (NULL);
}
