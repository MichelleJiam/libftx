/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstremovenode.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/18 17:51:37 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 17:54:06 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* unlinks node from list, repositioning previous and next pointers 
of neighbour nodes. Does not free node. If node is beginning of list, 
resets list pointer to next element. */

void	ft_dlstremovenode(t_dlist **head, t_dlist *node)
{
	if (!*head || !node)
		return ;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (node == *head)
		*head = node->next;
}
