/*
** EPITECH PROJECT, 2018
** unit_tests
** File description:
** creat_map
*/

#include "my.h"
#include "navy.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
	cr_redirect_stderr();
	cr_redirect_stdout();
}

Test(empty_map, simple, .init = redirect_all_std)
{
	char **tab = empty_map();

	cr_assert_str_eq(tab[0], "........");
	cr_assert_str_eq(tab[1], "........");
	cr_assert_str_eq(tab[2], "........");
	cr_assert_str_eq(tab[3], "........");
	cr_assert_str_eq(tab[4], "........");
	cr_assert_str_eq(tab[5], "........");
	cr_assert_str_eq(tab[6], "........");
	cr_assert_str_eq(tab[7], "........");
	my_strstrfree(tab);
}

Test(create_map, simple_too, .init = redirect_all_std)
{
	char **tab = str_to_tab(my_strdup("A src/pos/pos"));

	tab = check_start(2, tab);
	tab = create_map(tab);
	cr_assert_str_eq(tab[0], "2345....");
	cr_assert_str_eq(tab[1], "2345....");
	cr_assert_str_eq(tab[2], ".345....");
	cr_assert_str_eq(tab[3], "..45....");
	cr_assert_str_eq(tab[4], "...5....");
	cr_assert_str_eq(tab[5], "........");
	cr_assert_str_eq(tab[6], "........");
	cr_assert_str_eq(tab[7], "........");
	my_strstrfree(tab);
}

Test(create_map, false, .init = redirect_all_std)
{
	char **tab = str_to_tab(my_strdup("A src/pos/pos5"));

	tab = check_start(2, tab);
	cr_assert(create_map(tab) == NULL);
}
