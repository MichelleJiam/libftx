/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstprint.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/26 17:58:16 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/26 17:58:16 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include <stdio.h>

void	ft_lstprint(t_list *lst)
{
	if (!lst)
		return ;
	printf("List content: ");
	while (lst != NULL)
	{
		printf("%d", (int)lst->content);
		lst = lst->next;
	}
	printf("\n");
}