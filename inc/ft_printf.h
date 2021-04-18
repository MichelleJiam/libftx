/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/18 19:25:03 by mjiam         #+#    #+#                 */
/*   Updated: 2021/04/18 22:19:42 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libftx.h"

typedef enum e_mod
{
	l = 1,
	ll = 2,
	h = 3,
	hh = 4
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
int				lenadjuster(t_format *format, size_t len);
int				format_parser(const char **input, t_format *format, va_list list,
				int *printcount);
void			precisionsetter(const char **input, t_format *format);
void			sizesetter(const char **input, t_format *format);
void			widthsetter(t_format *format, va_list list);
void			ftp_writer(const char *ptr, size_t len, int *printcount);
void			ftp_printer(const char c, size_t len, int *printcount);

/*
** converters
*/

int				ftp_conv_char(t_format *format, va_list list, int *printcount);
int				ftp_conv_hex(t_format *format, va_list list, int *printcount);
int				ftp_conv_num(t_format *format, va_list list, int *printcount);
int				ftp_conv_n(t_format *format, va_list list, int *printcount);
int				ftp_conv_percent(t_format *format, int *printcount);
int				ftp_conv_string(t_format *format, va_list list, int *printcount);

/*
** utils
*/

char			*ftp_signed_itoa(intmax_t n, t_format *format);
char			*ftp_unsigned_itoa(uintmax_t n, t_format *format, unsigned int base);

#endif
