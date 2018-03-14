/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_printf
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(my_printf, unknow_flag, .init = redirect_all_std)
{
	my_printf("%F%", 1);
	cr_assert_stdout_eq_str("%F%");
}

Test(my_printf, d_flag, .init = redirect_all_std)
{
	my_printf("test %d", 1, 6734);
	cr_assert_stdout_eq_str("test 6734");
}

Test(my_printf, c_flag, .init = redirect_all_std)
{
	my_printf("%c", 1, 'k');
	cr_assert_stdout_eq_str("k");
}

Test(my_printf, s_flag, .init = redirect_all_std)
{
	my_printf("%s", 1, "bonjour");
	cr_assert_stdout_eq_str("bonjour");
}
