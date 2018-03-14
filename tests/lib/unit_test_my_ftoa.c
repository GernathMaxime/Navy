/*
** EPITECH PROJECT, 2018
** lib_tests
** File description:
** my_ftoa.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_ftoa, all)
{
	cr_assert_str_eq(my_ftoa(19), "19.0");
	cr_assert_str_eq(my_ftoa(19.6), "19.60");
	cr_assert_str_eq(my_ftoa(19.987), "19.98");
}
