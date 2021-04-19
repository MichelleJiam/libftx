/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstprint.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/26 17:58:16 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/26 17:58:16 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Outputs content of a list of ints to stdout */

void	ft_lstprint_int(t_list *lst)
{
	if (!lst)
		return ;
	ft_putendl_fd("List content: ", 1);
	while (lst != NULL)
	{
		ft_putnbr_fd((intptr_t)lst->content, 1);
		ft_putstr_fd("\n", 1);
		lst = lst->next;
	}
	ft_putstr_fd("\n", 1);
}
