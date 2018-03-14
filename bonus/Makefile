##
## EPITECH PROJECT, 2017
## 101 pong
## File description:
## makefile
##

NAME	=	navy

SDIR	=	src/

SRC	=	$(SDIR)main.c	\
		$(SDIR)create_map.c	\
		$(SDIR)utilities.c	\
		$(SDIR)bot_utilities.c	\
		$(SDIR)advanced_bot.c	\
		$(SDIR)bot.c	\
		$(SDIR)bot_map.c	\
		$(SDIR)ncurses/ncurses_mode.c	\
		$(SDIR)ncurses/play_game.c	\
		$(SDIR)ncurses/init_online.c	\
		$(SDIR)ncurses/chose_shot.c	\
		$(SDIR)ncurses/last_utilities.c	\
		$(SDIR)ncurses/play_online.c	\
		$(SDIR)ncurses/socket.c	\
		$(SDIR)ncurses/human.c	\
		$(SDIR)ncurses/utilities.c

OBJ	=	$(SRC:.c=.o)

LIB	=	libmy.a

CC	=	gcc -g

CFLAGS	=	-W -Wall -Wextra

CPPFLAGS	=	-Iinclude -l ncurses -l c_graph_prog -lmy -L../lib/my

all:	$(LIB) $(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(SRC) $(CPPFLAGS)

$(LIB):
	make -C ../lib/my/

clean:
	rm -f $(OBJ)
	make clean -C ../lib/my/

fclean:	clean
	rm -f $(NAME)
	make fclean -C ../lib/my/

re:	fclean all

.PHONY: all re clean fclean
