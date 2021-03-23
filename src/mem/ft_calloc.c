/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 21:19:59 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:35:30 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* function contiguously allocates enough space for (count) objects that are 
(size) bytes of memory each and returns a pointer to the allocated memory.
The allocated memory is filled with bytes of value zero. */

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;
	size_t	total;

	i = 0;
	total = count * size;
	p = malloc(total);
	if (!p)
		return (NULL);
	while (total > i)
	{
		((unsigned char *)p)[i] = 0;
		i++;
	}
	return (p);
}
