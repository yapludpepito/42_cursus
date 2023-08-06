CC		=	c++
CFLAGS	=	-g -Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp

OBJ			= $(SRCS:.cpp=.o)
NAME	=	Iter
RM		=	rm -f
bold	:= $(shell tput bold)
green	:= $(shell tput setaf 2)
sgr0	:= $(shell tput sgr0)

all: $(NAME)

.cpp.o: $(SRCS)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@$(CC) ${OBJ} -o $(NAME) $(CFLAGS)
	@printf "[$(green)✔$(sgr0)] $(bold)$(green)Compiling Iter finished!$(sgr0)\n"

clean:
			@echo "-----  Cleaning all objects...  -----"
			@${RM} ${OBJ}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus