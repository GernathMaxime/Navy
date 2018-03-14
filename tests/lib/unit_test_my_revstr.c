/*
** EPITECH PROJECT, 2017
** CPool_libmy_2017
** File description:
** unit_test_my_revstr.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_revstr, simple)
{
	cr_assert_str_eq(my_revstr(my_strdup("ABC")), "CBA");
	cr_assert_str_eq(my_revstr(my_strdup("ABCD")), "DCBA");
	cr_assert_str_eq(my_revstr(my_strdup("91")), "19");
	cr_assert_str_eq(my_revstr(my_strdup("1")), "1");
}
