/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:06:20 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/11 16:33:41 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (0);
}
