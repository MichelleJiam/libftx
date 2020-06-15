/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 17:06:51 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/22 20:09:59 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include <stdlib.h>

t_list *ft_lstnew(void *content)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
