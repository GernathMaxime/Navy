/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** my_strncmp.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_strncmp, test)
{
	cr_assert(my_strncmp("1234", "2", 1) == -1);
	cr_assert(my_strncmp("9999", "8888", 4) == 1);
	cr_assert(my_strncmp("9", "8888", 4) < 0);
	cr_assert(my_strncmp("zei", "zei", 2) == 0);
	cr_assert(my_strncmp("cheval", "cheval", 3) == 0);
}
