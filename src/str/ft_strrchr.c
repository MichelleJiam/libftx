/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:06:20 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:45:51 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Identical to strchr(), except it locates the last occurrence of c. 
Returns a pointer to the located character, or NULL if the character does not 
appear in the string. */

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			tmp = &(*(char *)s);
		s++;
	}
	if (!*s)
	{
		if (*s == (unsigned char)c)
			tmp = &(*(char *)s);
		if (tmp)
			return (tmp);
	}
	return (NULL);
}
