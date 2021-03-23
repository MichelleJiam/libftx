/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:10:08 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:45:06 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Lexicographically compares the null-terminated strings s1 and s2, but
no more than n characters. Returns an integer greater than, equal to, 
or less than 0, depending on whether string s1 is greater than, equal to, 
or less than string s2.*/

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
