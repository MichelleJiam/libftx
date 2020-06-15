/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelhead.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 21:27:46 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/22 21:27:46 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

void	ft_lstdelhead(t_list **head)
{
	t_list *tmp;

	if (!head)
		return ;
	tmp = (*head)->next;
	(*head)->content = 0;
	free(*head);
	*head = tmp;
}
