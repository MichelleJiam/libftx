/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_strict.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:54:49 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/13 22:26:41 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Converts str to int representation and saves in *num. Returns 0 if success.
If over or under int limits, returns -1 and doesn't change *num. */

int	ft_atoi_strict(const char *str, int *num)
{
	int			negative;
	intmax_t	n;

	n = 0;
	ft_skipws(&str, 0);
	if (!str)
		return (0);
	negative = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		n = n * 10 + (*str - '0');
		if ((!negative && n > INT_MAX) || (negative && ((n * -1) < INT_MIN)))
			return (-1);
		str++;
	}
	if (negative)
		*num = n * -1;
	else
		*num = n;
	return (0);
}
