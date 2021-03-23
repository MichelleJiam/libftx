/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 15:37:20 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:47:09 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Allocates (with malloc(3)) and returns an array of strings obtained by 
splitting s using the character c as a delimiter. The array must be ended by a
NULL pointer. Returns NULL if allocation fails. */

static int	freeall(char **array, int wc)
{
	while (wc >= 0)
	{
		free(array[wc]);
		wc--;
	}
	free(array);
	return (0);
}

static char	*saveword(char const *str, char c)
{
	char	*word;
	int		i;

	word = NULL;
	i = 0;
	while (str[i] != c && str[i])
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	i = 0;
	while (str[i] != c && str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	makearr(char **array, char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			array[i] = saveword(s, c);
			if (!array[i])
				return (freeall(array, i - 1));
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	array[i] = NULL;
	return (1);
}

static int	countword(char const *str, char c)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			words++;
			while (*str != c && *str)
				str++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;

	if (!s)
		return (NULL);
	words = countword(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array || makearr(array, s, c) == 0)
		return (NULL);
	else
		return (array);
}
