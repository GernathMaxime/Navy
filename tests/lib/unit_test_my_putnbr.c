/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** my_putnbr
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(my_putnbr, simple, .init = redirect_all_std)
{
	my_putnbr(89, 1);
	cr_assert_stdout_eq_str("89");
}

Test(my_putnbr, simpe, .init = redirect_all_std)
{
	my_putnbr(-89, 1);
	cr_assert_stdout_eq_str("-89");
}

Test(my_putnbr, simpl, .init = redirect_all_std)
{
	my_putnbr(45689, 1);
	cr_assert_stdout_eq_str("45689");
}
