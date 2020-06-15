/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst2new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 20:13:46 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/22 20:13:46 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include <stdlib.h>

t_list2 *ft_lst2new(void *content, void *previous)
{
	t_list2 *new;

	new = (t_list2 *)malloc(sizeof(t_list2));
	if (!new)
		return (NULL);
	new->content = content;
	new->previous = previous;
	new->next = NULL;
	return (new);
}
