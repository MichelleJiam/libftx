/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 23:03:39 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/02 19:22:39 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/libftx.h"

int	main(void)
{
	if (ft_isalnum('a'))
		write(1, "yes\n", 4);
	
	char *cpy;

	cpy = ft_strdup("Hello world\n42");
	ft_putstr_fd(cpy, 1);
	return (0);
}
