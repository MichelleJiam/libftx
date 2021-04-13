/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_var_free.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 22:05:14 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/13 22:10:43 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Variadic function for freeing num amount of items. Returns ret. */

int	ft_var_free(int ret, int num, ...)
{
	va_list	list;
	void	*data;

	va_start(list, num);
	while (num)
	{
		data = va_arg(list, void *);
		free(data);
		num--;
	}
	va_end(list);
	return (ret);
}
