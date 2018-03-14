/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** my_putstr
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(my_putstr, simple, .init = redirect_all_std)
{
	my_putstr("Cheval", 1);
	cr_assert_stdout_eq_str("Cheval");
}

Test(my_putstr, simpl, .init = redirect_all_std)
{
	my_putstr("1", 2);
	cr_assert_stderr_eq_str("1");
}

Test(my_putstr, simpe, .init = redirect_all_std)
{
	my_putstr("Electromenager", 2);
	cr_assert_stderr_eq_str("Electromenager");
}
