/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_valid_atoia.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/19 15:21:58 by mjiam         #+#    #+#                 */
/*   Updated: 2021/07/19 15:29:46 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Converts num_str to int representation and saves in *num arg. 
Returns TRUE on successful conversion. If invalid input or outside int limits,
returns FALSE and doesn't change *num. Unlike atoi, non-number chars and 
non-leading whitespaces are treated as wrong input. */

bool	ft_valid_atoia(const char *num_str, int *num)
{
	bool		is_negative;
	intmax_t	res;

	res = 0;
	if (!num_str)
		return (false);
	ft_skipws(&num_str, 0);
	is_negative = (*num_str == '-');
	if (*num_str == '-' || *num_str == '+')
		num_str++;
	while (*num_str != '\0')
	{
		if (*num_str < '0' || *num_str > '9')
			return (false);
		res = res * 10 + (*num_str - '0');
		if ((!is_negative && res > INT_MAX)
			|| (is_negative && -(res) < INT_MIN))
			return (false);
		num_str++;
	}
	if (is_negative)
		*num = res * -1;
	else
		*num = res;
	return (true);
}
