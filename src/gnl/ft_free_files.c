/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_files.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/02 18:55:34 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/02 19:01:16 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* Frees the entire list starting from the given pointer, 
returns the code sent as parameter. */

int	ft_free_files(t_file **files, int code)
{
	t_file	*tmp;

	while (*files)
	{
		free((*files)->data);
		tmp = *files;
		*files = tmp->next;
		free(tmp);
	}
	*files = NULL;
	return (code);
}
