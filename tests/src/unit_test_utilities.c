/*
** EPITECH PROJECT, 2018
** unit_tests
** File description:
** utilities.c
*/

#include "my.h"
#include "navy.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
	cr_redirect_stdin();
}

Test(fill_board, simple, .init = redirect_all_std)
{
	info_t *board = malloc(sizeof(*board));
	char **tab = str_to_tab(my_strdup("1 src/pos/pos"));

	cr_assert(fill_board(board, 2, tab) == 0);
	cr_assert(fill_board(NULL, 2, tab) == 84);
	tab = str_to_tab(my_strdup("1 src/pos/pos5"));
	cr_assert(fill_board(board, 2, tab) == 84);
	my_strstrfree(tab);
}

Test(print_map, normal, .init = redirect_all_std)
{
	info_t *board = malloc(sizeof(*board));
	char **tab = str_to_tab(my_strdup("1 src/pos/pos"));

	fill_board(board, 2, tab);
	my_strstrfree(tab);
	print_map(board->en_map);
	print_game(board);
	cr_assert_stdout_neq_str("A");
}
