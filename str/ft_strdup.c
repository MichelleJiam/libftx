/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:17:48 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/10 15:11:38 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		return (0);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
