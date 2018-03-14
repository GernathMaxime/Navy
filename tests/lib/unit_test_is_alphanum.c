/*
** EPITECH PROJECT, 2018
** lib
** File description:
** is_alphanum.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(is_alphanum, full_check)
{
	cr_assert(is_alphanum("AZERTYUI") == 0);
	cr_assert(is_alphanum("aaaaa=aaaa") != 0);
	cr_assert(is_alphanum("a;ze") != 0);
	cr_assert(is_alphanum("a%") != 0);
	cr_assert(is_alphanum("a45678fdz") == 0);
	cr_assert(is_alphanum("   ") != 0);
	cr_assert(is_alphanum("a45678ZERTYJK") == 0);
}
