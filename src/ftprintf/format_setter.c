/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_setter.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/18 22:21:16 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 22:21:17 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void	widthsetter(t_format *format, va_list list)
{
	format->width = va_arg(list, int);
	if (format->width < 0)
	{
		format->width *= -1;
		format->left = 1;
	}
}

void	sizesetter(const char **input, t_format *format)
{
	if (**input == 'h')
	{
		if (*(*input + 1) == 'h')
		{
			format->modifier = hh;
			(*input)++;
		}
		else
			format->modifier = h;
	}
	else if (**input == 'l')
	{
		if (*(*input + 1) == 'l')
		{
			format->modifier = ll;
			(*input)++;
		}
		else
			format->modifier = l;
	}
}

void	precisionsetter(const char **input, t_format *format)
{
	if (*(*input + 1) == '*')
	{
		format->precision = -1;
		(*input)++;
	}
	else if (ft_isdigit(*(*input + 1)))
		format->precision = ft_atoi(*input + 1);
	else
		format->precision = 0;
}
