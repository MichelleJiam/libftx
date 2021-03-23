/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:54:49 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:34:18 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* converts the initial portion of the string pointed to by str 
to int representation. */

int	ft_atoi(const char *str)
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
		if (n >= 922337203685477580)
		{
			if (!negative)
				return (-1);
			return (0);
		}
		n = n * 10 + (*str - '0');
		str++;
	}
	if (negative)
		return (n * -1);
	return (n);
}
