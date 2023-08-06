# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubacqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 16:59:13 by pdubacqu          #+#    #+#              #
#    Updated: 2022/10/05 16:59:20 by pdubacqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c \
		ft_putnbr_base.c \
		ft_putulnbr_base.c \
		ft_putunbr.c \
		ft_putllnbr.c \
		ft_putunbr_base.c \
		ft_putlstr.c \

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

%.o : %.c
	$(CC) ${CFLAGS} -c $< -o $@

$(NAME): $(OBJ)
	ar rcs -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re
