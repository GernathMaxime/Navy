/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** my_getnbr.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_getnbr, simple)
{
	cr_assert(my_getnbr("1") == 1);
	cr_assert(my_getnbr(NULL) == 0);
	cr_assert(my_getnbr("--1") == 1);
	cr_assert(my_getnbr("++--+-1") == -1);
	cr_assert(my_getnbr("a-ef +345") == 345);
	cr_assert(my_getnbr("az-+-+- 21") == 21);
	cr_assert(my_getnbr("zefyu") == 0);
	cr_assert(my_getnbr("-23-") == -23);
}
