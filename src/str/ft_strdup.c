/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:17:48 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:42:52 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Allocates sufficient memory for a copy of the string s1, does the copy, 
and returns a pointer to it.  The pointer may subsequently be used as an 
argument to the function free(3). If insufficient memory is available, 
NULL is returned. */

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*s2;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	s2 = malloc(sizeof(*s1) * (len + 1));
	if (!s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
