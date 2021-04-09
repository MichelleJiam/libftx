/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 23:03:39 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/09 23:20:16 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/libftx.h"
#include <stdio.h>

int	main(void)
{
	if (ft_isalnum('a'))
		write(1, "yes\n", 4);
	
	char *cpy;
	cpy = ft_strdup("--- ft_stdup test ---\nHello world\n42\n");
	ft_putstr_fd(cpy, 1);

	// ft_intoverflow test
	printf("--- ft_intoverflow test ---\n");
	int a = INT_MAX - 5;
	int b = 5;
	int *res = (int *)malloc(sizeof(int));

	if (ft_intoverflow(res, a, b))
		printf("Overflow detected trying to sum [%d] + [%d]\n", a, b);
	else
		printf("No overflow. Sum of [%d] + [%d] = [%d]\n", a, b, *res);
	a = 60;
	b = -10;
	if (ft_intoverflow(res, a, b))
		printf("Overflow detected trying to sum [%d] + [%d]\n", a, b);
	else
		printf("No overflow. Sum of [%d] + [%d] = [%d]\n", a, b, *res);
	a = -2147483647;
	b = 2147483647;
	if (ft_intoverflow(res, a, b))
		printf("Overflow detected trying to sum [%d] + [%d]\n", a, b);
	else
		printf("No overflow. Sum of [%d] + [%d] = [%d]\n", a, b, *res);
	a = INT_MIN;
	b = -10;
	if (ft_intoverflow(res, a, b))
		printf("Overflow detected trying to sum [%d] + [%d]\n", a, b);
	else
		printf("No overflow. Sum of [%d] + [%d] = [%d]\n", a, b, *res);
	
	// ft_atoi_strict test
	printf("--- ft_atoi_strict test ---\n");
	intmax_t c = 2147483648;
	if (ft_atoi_strict("2147483648", res) < 0)
		printf("atoi_strict returns ERROR on %ld. res is %d\n", c, *res);
	else
		printf("atoi_strict returns OK on %ld. res is %d\n", c, *res);
	*res = 0;
	c = 4294967295;
	if (ft_atoi_strict("4294967295", res) < 0)
		printf("atoi_strict returns ERROR on %ld. res is %d\n", c, *res);
	else
		printf("atoi_strict returns OK on %ld. res is %d\n", c, *res);
	*res = 0;
	c = -2147483648;
	if (ft_atoi_strict("-2147483648", res) < 0)
		printf("atoi_strict returns ERROR on %ld. res is %d\n", c, *res);
	else
		printf("atoi_strict returns OK on %ld. res is %d\n", c, *res);
	*res = 0;
	c = -2147483649;
	if (ft_atoi_strict("-2147483649", res) < 0)
		printf("atoi_strict returns ERROR on %ld. res is %d\n", c, *res);
	else
		printf("atoi_strict returns OK on %ld. res is %d\n", c, *res);
	return (0);
}
