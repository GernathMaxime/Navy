/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** my_strcat.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_strcat, simple)
{
	cr_assert_str_eq(my_strcat(my_strdup("ch"), my_strdup("ien")), "chien");
	cr_assert_str_eq(my_strcat(my_strdup(""), my_strdup("ien")), "ien");
	cr_assert_str_eq(my_strcat(my_strdup("cheval"), NULL), "cheval");
	cr_assert_str_eq(my_strcat(my_strdup("chi"), my_strdup("en")), "chien");
	cr_assert_str_eq(my_strcat(my_strdup("ra"), my_strdup("ts")), "rats");
}
