/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 17:36:06 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/22 20:25:26 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

void	ft_lstadd_front(t_list **head, t_list *new)
{
	if (!head || !new)
		return ;
	new->next = *head;
	*head = new;
}
