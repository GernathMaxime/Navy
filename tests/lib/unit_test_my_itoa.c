/*
** EPITECH PROJECT, 2017
** bistro-matic
** File description:
** my_itoa
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_itoa, simple)
{
	cr_assert_str_eq(my_itoa(1), "1");
	cr_assert_str_eq(my_itoa(32), "32");
	cr_assert_str_eq(my_itoa(9999), "9999");
}

Test(my_itoa, neg)
{
	cr_assert_str_eq(my_itoa(-99), "-99");
	cr_assert_str_eq(my_itoa(-50), "-50");
}

Test(my_itoa, advanced)
{
	cr_assert_str_eq(my_itoa(0), "0");
	cr_assert_str_eq(my_itoa(123456789), "123456789");
}
