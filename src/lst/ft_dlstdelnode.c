/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstdelnode.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 22:52:49 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/13 23:13:24 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Takes a double-ended list head pointer, the node to be freed, and a del 
function to be called on the node’s content. Adjusts prev and next pointers.
Then calls del function and frees element itself. */

void	ft_dlstdelnode(t_dlist **head, t_dlist *node, void (*del)(void *))
{
	if (!*head || !node)
		return ;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (node == *head)
		*head = node->next;
	del(node->content);
	free(node);
}
