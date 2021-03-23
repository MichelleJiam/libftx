/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 20:03:12 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:47:42 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Lexicographically compares the null-terminated strings s1 and s2. 
Returns an integer greater than, equal to, or less than 0, 
depending on whether string s1 is greater than, equal to, 
or less than string s2.*/

int	ft_strcmp(void *s1, void *s2)
{
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = s1;
	str2 = s2;
	while ((str1[i] && str2[i]) && str1[i] == str2[i])
		i++;
	if (!str1[i] && !str2[i])
		return (0);
	return (str1[i] - str2[i]);
}
