/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** my_strstrdup.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(my_strstrdup, simple)
{
	char **test = malloc(sizeof(char *) * 4);
	char **output = NULL;

	test[0] = my_strdup("test");
	test[1] = my_strdup("");
	test[2] = my_strdup("ceci est un test");
	test[3] = NULL;
	output = my_strstrdup(test);
	cr_assert_str_eq(test[0], output[0]);
	cr_assert_str_eq(test[1], output[1]);
	cr_assert_str_eq(test[2], output[2]);
	my_strstrfree(test);
	my_strstrfree(output);
}
