/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 20:17:46 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 21:32:18 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* converts the initial portion of the string pointed to by str, 
representing an int in the specific base, to base 10 int representation. */

int	get_num(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c + 10 - 'a');
	else if (c >= 'A' && c <= 'F')
		return (c + 10 - 'A');
	return (-1);
}

int	withinrange(char c, int base)
{
	int	max;

	if (base <= 10)
		max = base - 1 + '0';
	else
		max = base - 11 + 'a';
	if (c >= '0' && c <= max)
		return (1);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	negative;
	int	n;
	int	res;

	n = 0;
	res = 0;
	ft_skipws(&str, 0);
	if (!str)
		return (0);
	negative = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	while (withinrange(*str, str_base) && n >= 0)
	{
		n = get_num(*str);
		res = res * str_base + n;
		str++;
	}
	if (negative)
		return (res * -1);
	return (res);
}
