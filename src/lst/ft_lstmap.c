/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 11:48:02 by mjiam         #+#    #+#                 */
/*   Updated: 2021/03/23 17:38:57 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Iterates the list lst and applies the function f to the content of each 
element. Creates a new list consisting of elements on which the function f
have been successfully applied. The del function is here to delete the content
of an element if needed. */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*next;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		next = ft_lstnew(f(lst->content));
		if (!next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, next);
		lst = lst->next;
	}
	return (new);
}
