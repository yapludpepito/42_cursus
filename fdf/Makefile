# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 16:35:42 by pdubacqu          #+#    #+#              #
#    Updated: 2022/11/23 12:59:33 by pdubacqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	source/display.c \
				source/fdf.c \
				source/get_next_line.c \
				source/get_next_line_utils.c \
				source/dda.c \
				source/utils.c \
				source/ft_isometric.c \
				source/utils_dda.c \
				source/reload_display.c \
				source/hook.c \
				source/check_maps.c \
				source/utils2.c

INCLUDE		= include/
MLX			= minilibx-linux/
CFLAGS		= -g
MLX_FLAGS	= -lm -lmlx -lX11 -lXext
NAME		= fdf
LIB			= minilibx-linux/libmlx_Linux.a

BGreen		= '\033[1;32m'
NC			= '\033[0m'

all: $(NAME)

$(NAME):
	@make -sC $(MLX) all
	@echo ${BGreen}Compiling MLX finished !${NC}
	@gcc $(SRC) -o $(NAME) $(LIB) $(CFLAGS) $(MLX_FLAGS) -L$(MLX) -I$(INCLUDE)
	@echo $(BGreen)Compiling FDF finished !$(NC)

clean:
	@make -sC $(MLX) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
