# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 16:35:42 by jlarrieu          #+#    #+#              #
#    Updated: 2022/11/28 17:38:09 by pdubacqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= mandatory/source/pipex.c \
			  mandatory/source/fork.c

SRC_B		= bonus/source/pipex.c \
			  bonus/source/fork.c \
			  bonus/source/multipipe.c \
			  bonus/source/make_first_pipe.c \
			  bonus/source/make_here_doc.c \
			  bonus/source/multipipe_here_doc.c \
			  bonus/gnl/get_next_line.c \
			  bonus/gnl/get_next_line_utils.c

LIBFT		= mandatory/libft/
CFLAGS		= -Werror -Wextra -Wall -g
NAME		= pipex
NAME_B		= pipex_bonus
LIB			= mandatory/libft/libft.a

BGreen		= \033[1;32m
NC			= \033[0m

all: $(NAME)

bonus: $(NAME_B)

$(NAME):
	@make -sC $(LIBFT) all
	@printf "✔️${BGreen} Compiling libft finished !${NC}\n"
	@gcc $(SRC) -o $(NAME) $(LIB) $(CFLAGS) 
	@printf "✔️$(BGreen) Compiling PIPEX finished !$(NC)\n"

$(NAME_B):
	@make -sC $(LIBFT) all
	@printf "✔️${BGreen} Compiling libft finished !${NC}\n"
	@gcc $(SRC_B) -o $(NAME_B) $(LIB) $(CFLAGS) 
	@printf "✔️$(BGreen) Compiling PIPEX's bonus finished !$(NC)\n"

clean:
	@make -sC $(LIBFT) clean

fclean: clean
	@rm -f $(NAME) $(NAME_B)
	@printf "✔️$(BGreen) Removing pipex's binaries done.$(NC)\n"
	@make -sC $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
