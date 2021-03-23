/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 13:48:12 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 22:36:10 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Allocates (with malloc(3)) and returns a copy of the string given as 
argument without the characters specified in the set argument at the beginning
and the end of the string. Returns NULL if allocation fails. */

static int	findend(char const *str, char const *set)
{
	int	end;
	int	i;

	i = 0;
	end = ft_strlen(str) - 1;
	while (set[i] && end > 0)
	{
		if (str[end] == set[i])
		{
			end--;
			i = 0;
		}
		else
			i++;
	}
	return (end);
}

static int	findstart(char const *str, char const *set)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (set[i])
	{
		if (str[start] == set[i])
		{
			start++;
			i = 0;
		}
		else
			i++;
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = findstart(s1, set);
	end = findend(s1, set);
	if (end <= start)
		new_str = ft_calloc(1, 1);
	else
		new_str = ft_substr(s1, start, end - start + 1);
	return (new_str);
}
