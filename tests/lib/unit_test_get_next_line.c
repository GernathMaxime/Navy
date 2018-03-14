/*
** EPITECH PROJECT, 2018
** unit_test_lib
** File description:
** get_next_line.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(get_next_line, full)
{
	int fd = open("lib/unit_test_get_next_line.c", O_RDONLY);

	cr_assert_str_eq("/*", get_next_line(fd));
	cr_assert_str_eq("** EPITECH PROJECT, 2018", get_next_line(fd));
	cr_assert_str_eq("** unit_test_lib", get_next_line(fd));
	cr_assert_str_eq("** File description:", get_next_line(fd));
	cr_assert_str_eq("** get_next_line.c", get_next_line(fd));
	cr_assert_str_eq("*/", get_next_line(fd));
	cr_assert_str_eq("", get_next_line(fd));
	cr_assert_str_eq("#include \"my.h\"", get_next_line(fd));
	cr_assert_str_eq("#include <criterion/criterion.h>", get_next_line(fd));
	cr_assert_str_eq("", get_next_line(fd));
	cr_assert_str_eq("Test(get_next_line, full)", get_next_line(fd));
}

Test(get_next_line, fail)
{
	cr_assert(get_next_line(123) == NULL);
}

Test(get_next_line, complete)
{
	int fd = open("lib/unit_test_get_next_line.c", O_RDONLY);
	FILE *stream = fopen("lib/unit_test_get_next_line.c", "r");
	size_t nb = 0;
	char *real = NULL;
	char *got = NULL;

	for (int i = 0; got || i == 0; i++) {
		cr_assert(my_strncmp(got, real, my_strlen(got)) == 0);
		got = get_next_line(fd);
		getline(&real, &nb, stream);
	}
}
