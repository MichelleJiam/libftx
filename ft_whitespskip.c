/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_whitespskip.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 20:52:12 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/22 20:52:12 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Checks if str[*i] is a whitespace character. If not, immediately returns 0.
If yes, skips until is not and then returns 1. */

int		ft_whitespskip(char *str, int *i)
{
	if (str[*i] != 32 && (str[*i] < 9 || str[*i] > 13))
		return (0);
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	return (1);
}