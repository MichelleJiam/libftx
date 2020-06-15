/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 13:48:14 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/10 19:25:08 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	len = 0;
	while (s[len])
	{
		new[len] = f(len, s[len]);
		len++;
	}
	new[len] = '\0';
	return (new);
}
