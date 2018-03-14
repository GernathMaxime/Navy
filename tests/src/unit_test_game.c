/*
** EPITECH PROJECT, 2018
** unit_tests
** File description:
** game.c
*/

#include "my.h"
#include "navy.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(is_coord, simple)
{
	cr_assert(is_coord(NULL) == 0);
	cr_assert(is_coord("pfo") == 0);
	cr_assert(is_coord("A1") == 1);

}

Test(is_ended, simple_too)
{
	info_t *board = malloc(sizeof(*board));

	board->my_map = str_to_tab(my_strdup(". . . . . . . ."));
	for (int i = 0; i < 8; i++)
		board->my_map[i] = my_strdup("........");
	board->en_map = str_to_tab(my_strdup(". . . . . . . ."));
	for (int i = 0; i < 8; i++)
		board->en_map[i] = my_strdup("........");
	cr_assert(is_ended(board) == 0);
	board->en_map[1] = my_strdup("xxxxxxx.");
	board->en_map[2] = my_strdup("xxxxxxx.");
	cr_assert(is_ended(board) == 1);
	my_strstrfree(board->my_map);
	board->my_map = board->en_map;
	cr_assert(is_ended(board) == 2);
	my_strstrfree(board->my_map);
}
