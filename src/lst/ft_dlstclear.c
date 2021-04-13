/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstclear.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 23:28:04 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/13 23:32:30 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Deletes list content using del and frees the entire given double-ended list.
Finally, the pointer to the list is set to NULL. */

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		tmp = *lst;
		*lst = tmp->next;
		free(tmp);
	}
	*lst = NULL;
}
