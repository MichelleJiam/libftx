/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 19:13:38 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 17:58:24 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Adds the element new at the end of the list, 
head being the first link of the list. */

void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list	*tmp;

	if (!head)
		return ;
	tmp = *head;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*head = new;
}
