/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 18:29:24 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/02 19:02:40 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include "libftx.h"

typedef struct s_file
{
	int				fd;
	char			*data;
	struct s_file	*next;
	struct s_file	*prev;
}				t_file;

int		get_next_line(int fd, char **line);
int		ft_free_files(t_file **files, int code);
int		ft_free_one_file(t_file **files, t_file *file);

#endif
