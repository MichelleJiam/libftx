/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setter.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 21:15:47 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 19:30:57 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	widthsetter(t_data *data, va_list list)
{
	data->width = va_arg(list, int);
	if (data->width < 0)
	{
		data->width *= -1;
		data->left = 1;
	}
}

void	sizesetter(const char **input, t_data *data)
{
	if (**input == 'h')
	{
		if (*(*input + 1) == 'h')
		{
			data->modifier = hh;
			(*input)++;
		}
		else
			data->modifier = h;
	}
	else if (**input == 'l')
	{
		if (*(*input + 1) == 'l')
		{
			data->modifier = ll;
			(*input)++;
		}
		else
			data->modifier = l;
	}
}

void	precisionsetter(const char **input, t_data *data)
{
	if (*(*input + 1) == '*')
	{
		data->precision = -1;
		(*input)++;
	}
	else if (ft_isdigit(*(*input + 1)))
		data->precision = ft_atoi(*input + 1);
	else
		data->precision = 0;
}
