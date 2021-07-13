/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intoverflow.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 21:21:10 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/09 22:39:54 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Checks for integer overflow in sum of a and b. 
If overflow, returns 1 without modifying result. 
If not, updates result with sum and returns 0. */

int	ft_intoverflow(int *result, int a, int b)
{
	if (((b > 0) && (a > INT_MAX - b)) ||
		((b < 0) && (a < INT_MIN - b)))
		return (1);
	else
	{
		*result = a + b;
		return (0);
	}
}
