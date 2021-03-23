/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:24:55 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:45:30 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Locates the first occurrence of the null-terminated string needle in the 
string haystack, where not more than len characters are searched.  
Characters that appear after a `\0' character are not searched.
If needle is an empty string, haystack is returned; if needle occurs nowhere 
in haystack, NULL is returned; otherwise a pointer to the first character of 
the first occurrence of needle is returned. */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i] && (i + j) < len)
		{
			j++;
			if (needle[j] == '\0')
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (NULL);
}
