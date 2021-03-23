/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst2add_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 19:13:38 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/22 20:21:48 by mjiam         ########   odam.nl         */
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
		*head = new;
}
