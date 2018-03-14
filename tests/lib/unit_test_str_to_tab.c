/*
** EPITECH PROJECT, 2018
** lib
** File description:
** str_to_tab
*/

#include "my.h"
#include <criterion/criterion.h>

Test(str_to_tab, nul)
{
	cr_assert(str_to_tab(NULL) == NULL);
}

Test(str_to_tab, quotes)
{
	char *str = my_strdup("\"bonjour je\" suis un test");
	char **got = str_to_tab(str);

	cr_assert_str_eq(got[0], "bonjour je");
	cr_assert_str_eq(got[1], "suis");
	cr_assert_str_eq(got[2], "un");
	cr_assert_str_eq(got[3], "test");
	cr_assert(got[4] == NULL);
}

Test(str_to_tab, empty)
{
	char *str = my_strdup("");
	char **got = str_to_tab(str);

	cr_assert_str_eq(got[0], "");
	cr_assert(got[4] == NULL);
}
