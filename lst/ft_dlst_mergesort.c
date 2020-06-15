/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlst_mergesort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/26 17:52:30 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/26 17:52:30 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

t_dlist	*mergelist(t_dlist *lsta, t_dlist *lstb)
{
	if (!lsta)
		return (lstb);
	if (!lstb)
		return (lsta);
	if (lsta->content < lstb->content)
	{
		lsta->next = mergelist(lsta->next, lstb);
		lsta->next->prev = lsta;
		lsta->prev = NULL;
		return (lsta);
	}
	else
	{
		lstb->next = mergelist(lsta, lstb->next);
		lstb->next->prev = lstb;
		lstb->prev = NULL;
		return (lstb);
	}
}

void	splitlist(t_dlist *lsta, t_dlist **lstb)
{
	t_dlist	*fast;
	t_dlist	*slow;

	fast = lsta;
	slow = lsta;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	*lstb = slow->next;
	slow->next = NULL;
}

t_dlist	*ft_dlst_mergesort(t_dlist *lst)
{
	t_dlist	*lstb;

	if (!lst || !lst->next)
		return (lst);
	splitlist(lst, &lstb);
	lst = ft_dlst_mergesort(lst);
	lstb = ft_dlst_mergesort(lstb);
	return (mergelist(lst, lstb));
}