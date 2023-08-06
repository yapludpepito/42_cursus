# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubacqu <pdubacqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 11:24:09 by pdubacqu          #+#    #+#              #
#    Updated: 2023/01/21 14:59:41 by pdubacqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC					=  Animal.cpp \
					   Cat.cpp \
					   Dog.cpp \
					   main.cpp \
					   WrongAnimal.cpp \
					   WrongCat.cpp \
					   Brain.cpp

CFLAGS				= -Wall -Wextra -Werror -std=c++98 -g
NAME				= Animal

blink				= \033[5m
NC					= \033[0m
bold				:= $(shell tput bold)
blue				:= $(shell tput setaf 4)
green				:= $(shell tput setaf 2)
red					:= $(shell tput setaf 1)
sgr0				:= $(shell tput sgr0)

all: $(NAME)

$(NAME):
	@c++ $(SRC) -o $(NAME) $(CFLAGS) 
	@printf "[$(green)✔$(sgr0)] $(bold)$(green)Compiling Animal finished!$(sgr0)\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "[$(red)✔$(sgr0)] $(bold)$(blue)Removing Animal binary.$(sgr0)\n"

re: fclean all

.PHONY: all clean fclean re