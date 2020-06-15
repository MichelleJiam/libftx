/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 11:31:11 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/07 17:14:43 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (!*str && *str == (unsigned char)c)
		return ((char *)str);
	return (0);
}
