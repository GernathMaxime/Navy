/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** str_to_tab.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(str_to_tab, test)
{
	char *str = my_strdup("Ceci est un test reltivement simple");
	char **output = str_to_tab(str);

	cr_assert_str_eq(output[0], "Ceci");
	cr_assert_str_eq(output[1], "est");
	cr_assert_str_eq(output[2], "un");
	cr_assert_str_eq(output[3], "test");
	cr_assert_str_eq(output[4], "reltivement");
	cr_assert_str_eq(output[5], "simple");
	my_strstrfree(output);
}
