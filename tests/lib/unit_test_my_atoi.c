/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** my_atoi.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_atoi, simple)
{
	cr_assert(my_atoi("1") == 1);
	cr_assert(my_atoi("123") == 123);
	cr_assert(my_atoi("001") == 1);
	cr_assert(my_atoi("-1") == -1);
	cr_assert(my_atoi("12345") == 12345);
}

Test(my_atoi, harder)
{
	cr_assert(my_atoi("-08") == -8);
	cr_assert(my_atoi("801") == 801);
	cr_assert(my_atoi("-09878") == -9878);
}
