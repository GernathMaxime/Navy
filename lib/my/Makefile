##
## EPITECH PROJECT, 2017
## bistr-matic
## File description:
## libmy
##

SRC	=	my_revstr.c	\
		my_strlen.c	\
		my_strdup.c	\
		my_strstrdup.c	\
		my_strstrfree.c	\
		my_putchar.c	\
		my_ftoa.c	\
		my_itoa.c	\
		my_strcmp.c	\
		my_strcat.c	\
		is_alphanum.c	\
		my_printf.c	\
		my_strncmp.c	\
		my_putnbr.c	\
		is_int_in.c	\
		nb_occ.c	\
		my_getnbr.c	\
		str_to_tab.c	\
		my_atoi.c	\
		my_putstr.c	\
		clean.c		\
		get_next_line.c	\
		my_chardup.c	\
		convert_bin.c	\
		my_calloc.c

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

CC      =       gcc

CFLAGS	=	-W -Wall -Wextra

CPPFLAGS	=	-I ../../include/

all:    lib

lib:	$(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean lib
