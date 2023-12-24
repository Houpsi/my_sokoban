##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## go go
##

SRC 	=	src/sokoban.c	\
			src/my_strlen.c	\
			src/map.c	\
			src/helper.c	\
			src/mini_printf.c	\
			src/util.c	\
			src/move.c	\
			src/end.c	\
			src/loose.c	\
			src/error.c

OBJ 	= 	$(SRC:.c=.o)

NAME 	=	my_sokoban

all: 	$(NAME)

$(NAME):	$(OBJ)
	gcc -lncurses -o $(NAME) $(OBJ) -I./src

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : 	fclean all
