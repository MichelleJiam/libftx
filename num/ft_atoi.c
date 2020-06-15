/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 17:54:49 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/22 20:09:48 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include <stdint.h>

int		ft_atoi(const char *str)
{
	int			sign;
	intmax_t	n;

	sign = 1;
	n = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (isdigit(*str))
	{
		if (n >= 922337203685477580)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		n = n * 10 + (*str - '0');
		str++;
	}
	return (sign * n);
}
