/*
** EPITECH PROJECT, 2018
** unit_test
** File description:
** check_start.c
*/

#include "my.h"
#include "navy.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(is_good_line, simple_test, .init = redirect_all_std)
{
	cr_assert(is_good_line("2:C1:C2") == 0);
	cr_assert(is_good_line("2:A1:B1") == 0);
	cr_assert(is_good_line("1:C2") == 84);
	cr_assert(is_good_line("7:C1:C2") == 84);
	cr_assert(is_good_line("2:C9:C2") == 84);
	cr_assert(is_good_line("2:J1:C2") == 84);
	cr_assert(is_good_line("2:C1:C8") == 84);
	cr_assert(is_good_line("2:C1:A1") == 84);
	cr_assert(is_good_line("2:C2:H4") == 84);
}

Test(get_pos, full, .init = redirect_all_std)
{
	char **tab = get_pos("src/pos/pos");

	cr_assert_str_eq(tab[0], "2:A1:A2");
	cr_assert_str_eq(tab[1], "3:B1:B3");
	cr_assert_str_eq(tab[2], "4:C1:C4");
	cr_assert_str_eq(tab[3], "5:D1:D5");
	cr_assert(get_pos("src/pos/pos2") == NULL);
	cr_assert(get_pos("cheval") == NULL);
	cr_assert(get_pos("src/pos/pos3") == NULL);
	cr_assert(get_pos("src/pos/pos4") == NULL);
	my_strstrfree(tab);
}

Test(check_start, simple, .init = redirect_all_std)
{
	char **tab = NULL;

	cr_assert(check_start(1, str_to_tab(my_strdup("bonjour"))) == NULL);
	cr_assert(check_start(3, str_to_tab(my_strdup("a az"))) == NULL);
	tab = check_start(2, str_to_tab(my_strdup("a src/pos/pos3")));
	cr_assert(tab == NULL);
}
