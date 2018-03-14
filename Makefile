##
## EPITECH PROJECT, 2017
## 101 pong
## File description:
## makefile
##

NAME	=	navy

SDIR	=	src/

SRC	=	$(SDIR)main.c			\
		$(SDIR)check_start.c		\
		$(SDIR)signal.c			\
		$(SDIR)creat_map.c		\
		$(SDIR)game.c			\
		$(SDIR)utilities.c

OBJ	=	$(SRC:.c=.o)

LIB	=	libmy.a

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra

CPPFLAGS	=	-Iinclude -lmy -Llib/my

all:	$(LIB) $(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(SRC) $(CPPFLAGS)

$(LIB):
	make -C lib/my/

clean:
	rm -f $(OBJ)
	make clean -C lib/my/
	make clean -C tests/

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my/
	make fclean -C tests/

re:	fclean all

tests_run:
	make -C tests/

coverage:
	gcovr -r .

.PHONY: all re clean fclean tests_run coverage
