/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 13:48:12 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/25 13:22:12 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	findend(char const *str, char const *set)
{
	int	end;
	int	i;

	end = 0;
	i = 0;
	while (str[end])
		end++;
	end--;
	while (set[i] && end > 0)
	{
		if (str[end] == set[i])
		{
			end--;
			i = 0;
		}
		if (str[end] != set[i])
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
		if (str[start] != set[i])
			i++;
	}
	return (start);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*tstr;
	int		start;
	int		end;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = findstart(s1, set);
	end = findend(s1, set);
	tstr = (char *)malloc((end - start < 0) ? 1 : (end - start + 2));
	if (!tstr)
		return (0);
	s1 += start;
	while (i < end - start + 1 && end - start >= 0)
	{
		tstr[i] = *s1;
		i++;
		s1++;
	}
	tstr[i] = '\0';
	return (tstr);
}
