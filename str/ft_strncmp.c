/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:10:08 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/12 13:47:40 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0 && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (str1[i] - str2[i]);
		else
		{
			i++;
			n--;
		}
	}
	return (0);
}
