/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** clean.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(clean, simple)
{
	cr_assert_str_eq(clean(my_strdup("bonjour")), "bonjour");
	cr_assert_str_eq(clean(my_strdup("      bonjour")), "bonjour");
	cr_assert_str_eq(clean(my_strdup("bon jour")), "bon jour");
	cr_assert_str_eq(clean(my_strdup("b     onjour")), "b onjour");
	cr_assert_str_eq(clean(my_strdup("ar \"sal  ut\"")), "ar \"sal  ut\"");
	cr_assert(clean(NULL) == NULL);
}
