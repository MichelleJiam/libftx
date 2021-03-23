/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 12:35:17 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:39:31 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* writes len bytes of value c (converted to an unsigned char) to the string b.
Returns first argument. */

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (len > 0)
	{
		((char *)b)[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
