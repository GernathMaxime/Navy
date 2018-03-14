/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** nb_occ.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(nb_occ, simple)
{
	cr_assert(nb_occ("du bon jambon", 'o') == 2);
	cr_assert(nb_occ("du bon jambon", ' ') == 2);
	cr_assert(nb_occ("du bon jambon", 'z') == 0);
	cr_assert(nb_occ("aaaaaaa", 'a') == 7);
	cr_assert(nb_occ("du tres tres bon jambon", 'e') == 2);
}
