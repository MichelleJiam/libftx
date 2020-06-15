# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mjiam <mjiam@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 11:09:19 by mjiam         #+#    #+#                  #
#    Updated: 2020/05/22 20:56:19 by mjiam         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ftlib.a

SRC =	$(addprefix $(FD_D), ft_putchar_fd.c ft_putendl_fd.c \
								ft_putnbr_fd.c ft_putstr_fd.c) \
		$(addprefix $(LST_D), ft_lst2add_back.c ft_lst2add_front.c \
								ft_lst2new.c \
								ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
								ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
								ft_lstmap.c ft_lstnew.c ft_lstsize.c) \
		$(addprefix $(MEM_D), ft_bzero.c ft_calloc.c ft_memccpy.c \
								ft_memchr.c ft_memcmp.c ft_memcpy.c \
								ft_memmove.c ft_memset.c) \
		$(addprefix $(NUM_D), ft_atoi.c ft_itoa.c) \
		$(addprefix $(STR_D), ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
								ft_strlcat.c ft_strlcpy.c ft_strlen.c \
								ft_strmapi.c ft_strncmp.c ft_strnstr.c \
								ft_strrchr.c ft_strtrim.c ft_substr.c) \
  		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_isupperc.c ft_tolower.c ft_toupper.c ft_whitespskip.c

OBJ = $(SRC:.c=.o)

FD_D	= fd/
LST_D	= lst/
MEM_D	= mem/
NUM_D	= num/
STR_D	= str/

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking library"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@echo "Compiling: $<"
	@gcc -o $@ -c $< $(CFLAGS)

clean:
	@echo "Cleaning"
	@rm -f $(OBJ)
	@rm -f bonus

fclean: clean
	@echo "Clean af"
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re