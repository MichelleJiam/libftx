/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_one_file.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/02 18:58:46 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/02 19:01:52 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Frees the element file and repositions previous and next pointers 
of remaining elements. */

int	ft_free_one_file(t_file **files, t_file *file)
{
	if (!*files || !file)
		return (-1);
	if (file->prev)
		file->prev->next = file->next;
	if (file->next)
		file->next->prev = file->prev;
	if (file == *files)
		*files = file->next;
	free(file);
	return (0);
}
