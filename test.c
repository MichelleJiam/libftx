/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 23:03:39 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/09 21:42:31 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/libftx.h"
#include <stdio.h>

int	main(void)
{
	if (ft_isalnum('a'))
		write(1, "yes\n", 4);
	
	char *cpy;

	cpy = ft_strdup("Hello world\n42\n");
	ft_putstr_fd(cpy, 1);

	int a = INT_MAX - 5;
	int b = 5;
	int *res = (int *)malloc(sizeof(int));

	if (ft_intoverflow(res, a, b))
		printf("Overflow detected trying to sum [%d] + [%d]\n", a, b);
	else
		printf("No overflow. Sum is [%d]\n", *res);
	return (0);
}
