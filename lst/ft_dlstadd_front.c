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

#include "ftlib.h"

void	ft_lst2add_front(t_list2 **head, t_list2 *new)
{
	if (!head || !new)
		return ;
	new->next = *head;
	(*head)->previous = new;
	*head = new;
	new->previous = NULL;
}
