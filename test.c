/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 23:03:39 by mjiam         #+#    #+#                 */
/*   Updated: 2021/07/19 15:47:49 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/libftx.h"
#include <stdio.h>
#include <time.h>

int	main(int ac, char **av)
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

	ft_printf("[%.3d], [%.2d], [%3d]\n", 1, 42, 13);

	t_dlist *list = NULL;
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			intptr_t num = ft_atoi(av[i]);
			t_dlist *node = ft_dlstnew((void*)num, NULL);
			ft_dlstadd_back(&list, node);
		}
		ft_lstprint_int((t_list*)list);
		list = ft_dlst_mergesort(list);
		ft_lstprint_int((t_list*)list);
		ft_lstfree((t_list **)&list);
	}

	char *str = "-2147483648";
	// char *str = "-asdf";
    // char *str = "++42";
    // char *str = "42222222222222";
	// char *str = "-2147483649";
    int atoia_test_num = 0;
	ft_printf("input: %s -> valid_atoia returns: %s, converted num: %d\n",
        str, ft_valid_atoia(str, &atoia_test_num) ? "true" : "false", atoia_test_num);

	return (0);
}
