/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftlib.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 16:36:42 by mjiam         #+#    #+#                 */
/*   Updated: 2020/05/26 18:01:53 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

typedef struct 		s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;


typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* fd */
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

/* lst */
t_dlist				*ft_dlst_mergesort(t_dlist *lst);
void				ft_dlstadd_back(t_dlist **head, t_dlist *new);
void				ft_dlstadd_front(t_dlist **head, t_dlist *new);
t_dlist 			*ft_dlstnew(void *content, void *previous);
void				ft_lstadd_back(t_list **head, t_list *new);
void				ft_lstadd_front(t_list **head, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list				*ft_lstnew(void *content);
void		ft_lstprint(t_list *lst);
int					ft_lstsize(t_list *lst);

/* mem */
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);

/* num */
int					ft_atoi(const char *str);
char				*ft_itoa(int n);

/* str */
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);

/* uncategorised */
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isupperc(char *str, int i);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_whitespskip(char *str, int *i);

#endif
