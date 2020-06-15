/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 19:13:38 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/22 20:21:48 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

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
