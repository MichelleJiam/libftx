/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 18:30:24 by mjiam          #+#    #+#                */
/*   Updated: 2019/11/14 11:36:09 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*makestring(char *str, int nc, long num, int neg)
{
	str[nc] = '\0';
	while (nc > 0)
	{
		str[nc - 1] = (num % 10) + '0';
		num /= 10;
		nc--;
	}
	if (neg)
		str[nc] = '-';
	return (str);
}

static int	numcount(long n)
{
	int nc;

	nc = 1;
	if (n < 0)
	{
		nc++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		nc++;
	}
	return (nc);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		neg;
	int		nc;

	num = n;
	nc = numcount(num);
	neg = 0;
	str = malloc(sizeof(char) * (nc + 1));
	if (!str)
		return (0);
	if (num < 0)
	{
		num = num * -1;
		neg = 1;
	}
	str = makestring(str, nc, num, neg);
	return (str);
}
