/*
** EPITECH PROJECT, 2017
** CPool_libmy_2017
** File description:
** unit_test_my_strlen
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strlen, simple)
{
	cr_assert(my_strlen("123") == 3);
	cr_assert(my_strlen("Hello World") == 11);
	cr_assert(my_strlen("") == 0);
}
