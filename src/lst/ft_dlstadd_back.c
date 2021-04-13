/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstadd_back.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/02 19:19:00 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/02 19:19:03 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Adds the element new at the end of the double-ended list, 
head being the first link of the list. */

void	ft_dlstadd_back(t_dlist **head, t_dlist *new)
{
	t_dlist	*tmp;

	if (!head)
		return ;
	tmp = *head;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
		ft_dlstadd_front(head, new);
}
