/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 11:42:00 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/22 20:50:39 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		if (*lst == tmp)
			*lst = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = tmp->next;
	}
	*lst = NULL;
}
