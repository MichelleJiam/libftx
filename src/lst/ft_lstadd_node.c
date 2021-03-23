/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_node.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 17:45:10 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 22:45:45 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* appends new to given node location, suffixing any following nodes */

void	ft_lstadd_node(t_list **location, t_list *new)
{
	t_list	*save;
	t_list	*tmp;

	if (!location)
		return ;
	if (!*location)
	{
		*location = new;
		return ;
	}
	save = (*location)->next;
	(*location)->next = new;
	if (!save)
		return ;
	tmp = (ft_lstlast(new));
	tmp->next = save;
}