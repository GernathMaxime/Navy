/*
** EPITECH PROJECT, 2018
** unit_tests_lib
** File description:
** convert_bin
*/

#include "my.h"
#include <criterion/criterion.h>

Test(convert_bin, simple)
{
	char *str = my_strdup("10000000000000000000000000000000");

	cr_assert(convert_bin("00000000000000000000000000000000", 0) == 0);
	cr_assert(convert_bin("00000000000000000000000000000001", 0) == 1);
	cr_assert(convert_bin("00000000000000000000000000000010", 0) == 2);
	cr_assert(convert_bin("00000000000000000000000000000011", 0) == 3);
	cr_assert(convert_bin("10000000000000000000000000000001", 0) == -1);
	cr_assert(convert_bin("10000000000000000000000000000010", 0) == -2);
	cr_assert(convert_bin("10000000000000000000000000000011", 0) == -3);
	cr_assert(convert_bin("00000000000000000000000111001000", 0) == 456);
	cr_assert(convert_bin("00000000000000000", 0) == 0);
	cr_assert(convert_bin(NULL, 0) == 0);
	cr_assert(convert_bin(str, 1) == 1);
	free(str);
}
