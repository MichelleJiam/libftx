/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/26 16:34:27 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/26 16:36:33 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Allocates sufficient memory for a copy of the string s1, 
does the copy up to atmost len bytes, and returns a pointer to it.  
The pointer may subsequently be used as an argument to the function free(3). 
If insufficient memory is available, NULL is returned. */

char	*ft_strndup(const char *s1, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = malloc(sizeof(*s1) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
