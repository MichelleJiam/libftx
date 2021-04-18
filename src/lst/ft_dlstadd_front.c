/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstadd_front.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/02 19:19:11 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/02 19:19:11 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Adds the element new at the beginning of the double-ended list,
head being the first link of the list. */

void	ft_dlstadd_front(t_dlist **head, t_dlist *new)
{
	if (!head || !new)
		return ;
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
}
