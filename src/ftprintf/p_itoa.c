/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_itoa.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 18:30:24 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 19:46:49 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static char		*makestring(char *str, size_t *nc, uintmax_t num, t_format *data)
{
	int		comma;

	comma = 0;
	str[*nc] = '\0';
	while (*nc > 0)
	{
		if (data->group && comma == 3)
		{
			str[*nc - 1] = ',';
			comma = 0;
			(*nc)--;
		}
		str[*nc - 1] = (num % 10) + '0';
		num /= 10;
		(*nc)--;
		comma++;
	}
	return (str);
}

static size_t	a_numcount(size_t nc, intmax_t n, t_format *data)
{
	size_t	newnc;

	newnc = nc;
	if (nc > 3 && n >= 0)
	{
		if (nc % 3 == 0)
			newnc += (nc / 3) - 1;
		else
			newnc += nc / 3;
	}
	if (newnc == nc)
		data->group = 0;
	return (newnc);
}

static size_t	numcount(intmax_t n)
{
	size_t nc;

	nc = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nc++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		nc++;
	}
	return (nc);
}

char			*p_itoa(intmax_t n, t_format *data)
{
	char		*str;
	int			neg;
	size_t		nc;
	uintmax_t	num;

	neg = 0;
	nc = numcount(n);
	if (data->group)
		nc = a_numcount(nc, n, data);
	if ((int)nc < data->precision)
		nc = data->precision;
	str = malloc(sizeof(char) * (nc + 1));
	if (!str)
		return (0);
	if (n < 0)
	{
		if (n != LONG_MIN)
			n *= -1;
		neg = 1;
	}
	num = n;
	str = makestring(str, &nc, num, data);
	if (neg)
		str[nc] = '-';
	return (str);
}
