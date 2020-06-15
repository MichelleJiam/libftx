/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:12:26 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/19 13:10:42 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*newstr;

	i = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (0);
	while (*s1)
	{
		newstr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		newstr[i] = *s2;
		i++;
		s2++;
	}
	newstr[i] = '\0';
	return (newstr);
}
