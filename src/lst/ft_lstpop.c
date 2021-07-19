/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstpop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 17:24:43 by mjiam         #+#    #+#                 */
/*   Updated: 2021/07/19 15:38:51 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* frees last node of list without freeing contents */

void	ft_lstpop(t_list **list, bool free_content)
{
	t_list	*last;
	t_list	*tmp;

	last = ft_lstlast(*list);
	tmp = *list;
	if (list == NULL)
		return ;
	while (tmp->next != last)
		tmp = tmp->next;
	if (free_content == true)
		free(last->content);
	free(last);
	tmp->next = NULL;
}
