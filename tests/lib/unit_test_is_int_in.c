/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** is_int_in
*/

#include "my.h"
#include <criterion/criterion.h>

Test(is_int_in, simple)
{
	cr_assert(is_int_in("32", MIN, MAX) == 0);
	cr_assert(is_int_in("-32", -33, -31) == 0);
	cr_assert(is_int_in("0", MIN, 0) == 0);
	cr_assert(is_int_in("0", 1, MAX) == 84);
	cr_assert(is_int_in("17", MIN, 16) == 84);
	cr_assert(is_int_in("9999999999999999", MIN, MAX) == 84);
	cr_assert(is_int_in("A", MIN, MAX) == 84);
	cr_assert(is_int_in("9-99", MIN, MAX) == 84);
	cr_assert(is_int_in(my_itoa(MAX), MIN, MAX - 1) == 84);
	cr_assert(is_int_in(my_itoa(MAX), MIN, MAX) == 0);
	cr_assert(is_int_in("1134564532", MIN, MAX) == 0);
	cr_assert(is_int_in("3134564532", MIN, MAX) == 84);
	cr_assert(is_int_in(NULL, MIN, MAX) == 84);
}
