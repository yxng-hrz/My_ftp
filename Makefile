##
## EPITECH PROJECT, 2024
## B-NWP-400-PAR-4-1-myftp-guillaume.houriez
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/serv.c \
		src/client.c \
		src/command_hand.c \
		src/command_handd.c	\
		src/lib.c \
		src/parser.c \
		src/authent.c	\
		src/command.c	\
		src/command_ret.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -g3 -I ./includes

NAME	=	myftp

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
