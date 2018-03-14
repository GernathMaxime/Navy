/*
** EPITECH PROJECT, 2017
** unit_test_lib
** File description:
** unit_test_my_chardup
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_chardup, simple)
{
	cr_assert_str_eq(my_chardup('a'), "a");
	cr_assert_str_eq(my_chardup(' '), " ");
	cr_assert_str_eq(my_chardup('o'), "o");
	cr_assert_str_eq(my_chardup('_'), "_");
}
