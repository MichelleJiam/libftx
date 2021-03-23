/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 13:48:14 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:48:42 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Applies the function f to each character of the string passed as argument 
to create a new string (with malloc(3)) resulting from successive applications 
of f. Returns a pointer to the new string or NULL if allocation fails. */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		len;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	len = 0;
	while (s[len])
	{
		new[len] = f(len, s[len]);
		len++;
	}
	new[len] = '\0';
	return (new);
}
