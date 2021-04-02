/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstnew.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/02 19:19:31 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/02 19:19:31 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Allocates (with malloc(3)) and returns a new double-ended element. 
The variable content is initialized with the value of the parameter content. 
The variable prev is initialized to the parameter previous (preceding element).
The variable next is initialized to NULL. */

t_dlist	*ft_dlstnew(void *content, t_dlist *previous)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->content = content;
	new->prev = previous;
	new->next = NULL;
	return (new);
}
