/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:49:54 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/12 17:19:28 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;

	i = 0;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (start + len > slen)
		str = malloc(sizeof(char) * (slen - start + 1));
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (len > 0 && start < slen)
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
