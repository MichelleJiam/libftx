/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/18 19:25:03 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 19:46:53 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libftx.h"

typedef enum	e_mod
{
	l = 1, ll = 2, h = 3, hh = 4
}				t_mod;

typedef struct	s_format
{
	char		type;
	t_mod		modifier;
	int			left;
	int			zero;
	int			precision;
	int			hash;
	int			group;
	char		sp_plus;
	int			sign;
	int			size;
	int			width;
	char		space;
}				t_format;

int				ft_printf(const char *input, ...);
int				adjuster(t_format *data, size_t len);
int				converter(t_format *data, va_list list, int *printcount);
void			datainitialiser(t_format *data);
void			flagchecker(const char **input, t_format *data);
int				isvalid(const char **input, t_format *data);
int				parser(const char **input, t_format *data, va_list list,
				int *printcount);
void			precisionsetter(const char **input, t_format *data);
void			printer(const char c, size_t len, int *printcount);
void			sizesetter(const char **input, t_format *data);
int				typefinder(const char **input);
void			widthsetter(t_format *data, va_list list);
void			writer(const char *ptr, size_t len, int *printcount);

/*
** converters
*/

int				conv_char(t_format *data, va_list list, int *printcount);
int				conv_hex(t_format *data, va_list list, int *printcount);
int				conv_int(t_format *data, va_list list, int *printcount);
int				conv_n(t_format *data, va_list list, int *printcount);
int				conv_percent(t_format *data, int *printcount);
int				conv_string(t_format *data, va_list list, int *printcount);

/*
** utils
*/

char			*p_itoa(intmax_t n, t_format *data);
char			*u_itoa(uintmax_t n, t_format *data, unsigned int base);

#endif
