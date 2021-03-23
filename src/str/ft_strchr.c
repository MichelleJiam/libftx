/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 11:31:11 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:43:03 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Locates the first occurrence of c (converted to a char) in the string 
pointed to by s.  The terminating null character is considered to be part of 
the string; therefore if c is `\0', the function locates the terminating `\0'.
Returns a pointer to the located character, or NULL if the character does not 
appear in the string. */

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
