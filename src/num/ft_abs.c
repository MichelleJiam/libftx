/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/25 21:47:27 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/25 21:48:29 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* returns absolute value of a number */

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
