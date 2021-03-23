/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst2add_front.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 20:26:10 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/22 20:26:10 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Adds the element new at the beginning of the double-ended list,
alst being the first link of the list. */

void	ft_dlstadd_front(t_dlist **head, t_dlist *new)
{
	if (!head || !new)
		return ;
	new->next = *head;
	(*head)->prev = new;
	*head = new;
	new->prev = NULL;
}
