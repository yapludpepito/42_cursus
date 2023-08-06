# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 16:59:13 by pdubacqu          #+#    #+#              #
#    Updated: 2022/11/23 12:28:43 by pdubacqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	make_big_list.c \
		make_five.c \
		make_lst.c \
		make.c \
		move.c \
		move2.c \
		move3.c \
		push_swap.c \
		swap_value.c \
		utils.c \
		utils2.c \
		utils3.c \
		utils4.c \
		check_list.c

CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@gcc $(SRC) -o $(NAME) $(CFLAGS)
		@echo $(BGreen)Compiling PUSH_SWAP finished !$(NC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
