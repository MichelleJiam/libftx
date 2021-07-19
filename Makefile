# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mjiam <mjiam@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 11:09:19 by mjiam         #+#    #+#                  #
#    Updated: 2021/07/19 15:30:09 by mjiam         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libftx.a

HEADER	=	libftx.h

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

SRC		=	$(addprefix $(CHR_D), ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c \
				ft_isprint.c ft_isupperc.c \
				ft_tolower.c ft_toupper.c \
				ft_skipws.c) \
			$(addprefix $(FD_D), ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c) \
			$(addprefix $(PRINT_D), ftp_conv_char.c ftp_conv_hex.c \
				ftp_conv_num.c ftp_conv_string.c \
				ft_printf.c ftp_signed_itoa.c \
				format_parser.c ftp_printer.c \
				format_setter.c ftp_unsigned_itoa.c) \
			$(addprefix $(GNL_D), get_next_line.c \
				ft_free_files.c ft_free_one_file.c) \
			$(addprefix $(LST_D), ft_dlst_mergesort.c ft_dlstadd_back.c \
				ft_dlstadd_front.c ft_dlstdelnode.c \
				ft_dlstlast.c ft_dlstnew.c \
				ft_dlstremovenode.c \
				ft_lstadd_back.c ft_lstadd_front.c \
				ft_lstadd_node.c ft_lstclear.c \
				ft_lstdelhead.c ft_lstdelone.c \
				ft_lstfree.c ft_lstiter.c \
				ft_lstlast.c ft_lstmap.c \
				ft_lstnew.c ft_lstpop.c \
				ft_lstprint_int.c ft_lstsize.c) \
			$(addprefix $(MEM_D), ft_bzero.c ft_calloc.c \
				ft_memccpy.c ft_memchr.c \
				ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c \
				ft_var_free.c) \
			$(addprefix $(NUM_D), ft_abs.c ft_atoi_base.c \
				ft_atoi_strict.c ft_atoi.c \
				ft_intoverflow.c ft_itoa.c \
				ft_valid_atoia.c) \
			$(addprefix $(STR_D), ft_split.c ft_strchr.c \
				ft_strcmp.c ft_strdup.c \
				ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c \
				ft_strmapi.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c \
				ft_strtrim.c ft_substr.c \
				ft_strclen.c ft_strndup.c)

OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CHR_D	=	char/
FD_D	=	fd/
PRINT_D	=	ftprintf/
GNL_D	=	gnl/
LST_D	=	lst/
MEM_D	=	mem/
NUM_D	=	num/
STR_D	=	str/

SRC_DIR	=	src/
INC_DIR	=	inc/
OBJ_DIR	=	obj/

# COLORS
CYAN	= 	\033[0;36m
PURPLE	= 	\033[0;35m
BLUE	= 	\033[0;34m
RESET	= 	\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(PURPLE)Linking library$(RESET)"
	@ar cr $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Library $(CYAN)$@$(RESET) made"	

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@echo "$(PURPLE)Compiling: $<$(RESET)"
	@$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@echo "$(BLUE)Cleaning$(RESET)"
	@rm -rf $(OBJ_DIR)
	@rm -rf test
	@echo "$(BLUE)Removed: $(OBJ_DIR)$(RESET)"

fclean: clean
	@echo "$(BLUE)Removing: $(NAME)$(RESET)"
	@rm -rf $(NAME)
	@echo "$(BLUE)Clean af$(RESET)"

re:
	@echo "$(BLUE)Once more from the top$(RESET)"
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re