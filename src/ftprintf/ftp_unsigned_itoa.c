/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftp_unsigned_itoa.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/18 22:26:17 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 22:26:52 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static size_t	a_numcount(size_t nc)
{
	size_t	newnc;

	newnc = nc;
	if (nc > 3)
	{
		if (nc % 3 == 0)
			newnc += (nc / 3) - 1;
		else
			newnc += nc / 3;
	}
	return (newnc);
}

static size_t	unumcount(uintmax_t n, unsigned int base, t_format *format)
{
	size_t	nc;

	nc = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		nc++;
	}
	if (format->type == 'u' && format->group)
		nc = a_numcount(nc);
	if ((int)nc < format->precision)
		nc = format->precision;
	return (nc);
}

static void	setfinder(t_format *format, char **set)
{
	if (format->type == 'u')
		*set = "0123456789";
	else if (format->type == 'X')
		*set = "0123456789ABCDEF";
	else
		*set = "0123456789abcdef";
}

static char	*a_makestring(uintmax_t n, t_format *format, size_t nc, char *str)
{
	int		comma;
	char	*set;

	comma = 0;
	setfinder(format, &set);
	str[nc] = '\0';
	while (nc > 0)
	{
		if (comma == 3)
		{
			str[nc - 1] = ',';
			comma = 0;
			nc--;
		}
		str[nc - 1] = set[n % 10];
		n /= 10;
		nc--;
		comma++;
	}
	return (str);
}

char	*ftp_unsigned_itoa(uintmax_t n, t_format *format, unsigned int base)
{
	char			*str;
	char			*set;
	size_t			nc;

	nc = unumcount(n, base, format);
	str = malloc(sizeof(char) * (nc + 1));
	if (!str)
		return (0);
	if (format->type == 'u' && format->group)
		str = a_makestring(n, format, nc, str);
	else
	{
		setfinder(format, &set);
		str[nc] = '\0';
		while (nc > 0)
		{
			str[nc - 1] = set[n % base];
			n /= base;
			nc--;
		}
	}
	return (str);
}
