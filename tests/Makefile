##
## EPITECH PROJECT, 2017
## bistro-matic
## File description:
## Makefile
##

SDIR	=	../src/

SRC	=	$(SDIR)check_start.c	\
		$(SDIR)creat_map.c	\
		$(SDIR)game.c	\
		$(SDIR)signal.c	\
		$(SDIR)utilities.c

LDIR	=	../lib/my/

LIB	=	$(LDIR)my_revstr.c	\
		$(LDIR)my_strlen.c	\
		$(LDIR)my_strdup.c	\
		$(LDIR)my_strstrdup.c	\
		$(LDIR)my_strstrfree.c	\
		$(LDIR)my_putchar.c	\
		$(LDIR)my_itoa.c	\
		$(LDIR)my_strcmp.c	\
		$(LDIR)my_strcat.c	\
		$(LDIR)is_alphanum.c	\
		$(LDIR)my_printf.c	\
		$(LDIR)my_strncmp.c	\
		$(LDIR)my_putnbr.c	\
		$(LDIR)is_int_in.c	\
		$(LDIR)nb_occ.c	\
		$(LDIR)my_getnbr.c	\
		$(LDIR)str_to_tab.c	\
		$(LDIR)my_atoi.c	\
		$(LDIR)my_putstr.c	\
		$(LDIR)clean.c	\
		$(LDIR)convert_bin.c	\
		$(LDIR)get_next_line.c	\
		$(LDIR)my_chardup.c

LIB_UT_DIR	=	lib/

SRC_UT_DIR	=	src/

SRC_UT	=	$(LIB_UT_DIR)unit_test_my_strlen.c		\
		$(LIB_UT_DIR)unit_test_my_revstr.c		\
		$(LIB_UT_DIR)unit_test_clean.c		\
		$(LIB_UT_DIR)unit_test_get_next_line.c		\
		$(LIB_UT_DIR)unit_test_my_strstrdup.c		\
		$(LIB_UT_DIR)unit_test_my_str_to_tab.c		\
		$(LIB_UT_DIR)unit_test_my_printf.c	\
		$(LIB_UT_DIR)unit_test_str_to_tab.c	\
		$(LIB_UT_DIR)unit_test_my_strdup.c	\
		$(LIB_UT_DIR)unit_test_is_alphanum.c	\
		$(LIB_UT_DIR)unit_test_my_putstr.c	\
		$(LIB_UT_DIR)unit_test_my_chardup.c	\
		$(LIB_UT_DIR)unit_test_my_getnbr.c	\
		$(LIB_UT_DIR)unit_test_nb_occ.c	\
		$(LIB_UT_DIR)unit_test_my_putnbr.c	\
		$(LIB_UT_DIR)unit_test_is_int_in.c	\
		$(LIB_UT_DIR)unit_test_my_strcat.c	\
		$(LIB_UT_DIR)unit_test_convert_bin.c	\
		$(LIB_UT_DIR)unit_test_my_strncmp.c	\
		$(LIB_UT_DIR)unit_test_my_strcmp.c	\
		$(LIB_UT_DIR)unit_test_my_atoi.c	\
		$(LIB_UT_DIR)unit_test_my_itoa.c	\
		$(SRC_UT_DIR)unit_test_check_start.c	\
		$(SRC_UT_DIR)unit_test_utilities.c	\
		$(SRC_UT_DIR)unit_test_game.c	\
		$(SRC_UT_DIR)unit_test_creat_map.c

OBJ	=	$(LIB:.c=.o) $(SRC:.c=.o) $(SRC_UT:.c=.o)

CFLAGS	=	-Wall -Wextra -W --coverage

CPPFLAGS	=	-I../include -lcriterion

NAME	=	units

all:	$(NAME)
	./units
	cp ../src/*.gc* ../
	cp ../lib/my/*.gc* ../

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)
	rm -f src/*.gc*
	rm -f lib/*.gc*

clean:
	rm -f $(OBJ)
	rm -f ../*.gc*
	rm -f ../src/*.gc*
	rm -f ../lib/my/*.gc*
	rm -f src/*.gc*
	rm -f lib/*.gc*
	rm -f my_*

fclean:	clean
	rm -f $(NAME)

re:	fclean all
