/*
** EPITECH PROJECT, 2017
** CPool_libmy_2017
** File description:
** unit_test_my_strdup
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_strdup, simple)
{
	cr_assert_str_eq(my_strdup("Hello World"), "Hello World");
	cr_assert_str_eq(my_strdup(""), "");
	cr_assert_str_eq(my_strdup("Hello"), "Hello");
	cr_assert_str_eq(my_strdup("___"), "___");
}
