/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isupperc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 19:36:28 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/22 19:36:28 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* tests for uppercase character. Return zero if the character tests false
and return 1 if the character tests true. */

int	ft_isupperc(char *str, int i)
{
	if (str[i] > 64 && str[i] < 91)
		return (1);
	return (0);
}
