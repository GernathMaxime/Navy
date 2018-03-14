/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** my_strcmp.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_strcmp, test)
{
	cr_assert(my_strcmp("1234", "2") == 1);
	cr_assert(my_strcmp("9999", "8888") == 1);
	cr_assert(my_strcmp("654", "653") == 1);
	cr_assert(my_strcmp("ziz", "oui") == 1);
	cr_assert(my_strcmp("2", "1234") == -1);
	cr_assert(my_strcmp("8888", "9999") == -1);
	cr_assert(my_strcmp("653", "654") == -1);
	cr_assert(my_strcmp("oui", "ziz") == -1);
	cr_assert(my_strcmp("cheval", "cheval") == 0);
	cr_assert(my_strcmp("2", "2") == 0);
}
