/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 16:06:55 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/02 19:15:34 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*makeline(char **data)
{
	char	*line;
	char	*tmp;
	size_t	len;

	line = NULL;
	tmp = NULL;
	if (ft_strchr(*data, '\n'))
		len = ft_strclen(*data, '\n');
	else
		len = ft_strlen(*data);
	line = ft_substr(*data, 0, len);
	if (ft_strchr(*data, '\n'))
	{
		len++;
		tmp = ft_strdup(*data + len);
	}
	free(*data);
	*data = tmp;
	return (line);
}

int	read_file(t_file *file, int fd)
{
	int		ret;
	char	*readbuf;
	char	*temp;

	readbuf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!readbuf)
		return (-1);
	ret = read(fd, readbuf, BUFFER_SIZE);
	readbuf[ret] = '\0';
	temp = ft_strjoin(file->data, readbuf);
	free(file->data);
	file->data = temp;
	free(readbuf);
	if (!file->data)
		return (-1);
	return (ret);
}

t_file	*check_files(t_file **files, int fd)
{
	t_file	*file;

	file = *files;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->fd = fd;
	file->data = ft_strdup("");
	if (!file->data)
		return (NULL);
	file->next = *files;
	file->prev = NULL;
	if (*files && (*files)->prev)
		(*files)->prev = file;
	*files = file;
	return (file);
}

int	get_next_line(int fd, char **line)
{
	int				ret;
	static t_file	*files = NULL;
	t_file			*file;

	ret = 1;
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (-1);
	file = check_files(&files, fd);
	if (!file)
		return (ft_free_files(&files, -1));
	while (ret)
	{
		ret = read_file(file, fd);
		if (ft_strchr(file->data, '\n'))
			break ;
	}
	if (ret < 0)
		return (ft_free_files(&files, -1));
	*line = makeline(&file->data);
	if (!*line)
		return (ft_free_files(&files, -1));
	if (ret < BUFFER_SIZE && !file->data)
		return (ft_free_one_file(&files, file));
	return (1);
}
