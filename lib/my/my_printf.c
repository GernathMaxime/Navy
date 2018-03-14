/*
** EPITECH PROJECT, 2017
** printf
** File description:
** main function
*/

#include "my.h"

const function_t array[] = {
		{'d', &my_printf_nbr},
		{'s', &my_printf_str},
		{'c', &my_printf_char},
};

static void which_flag(char c, va_list ap, int output)
{
	int flag = 0;

	for (int i = 0; i < NB_FLAGS; i++) {
		if (array[i].flag == c) {
			array[i].functions(ap, output);
			flag++;
		}
	}
	if (flag == 0 && c != '\0') {
		my_putchar('%', output);
		my_putchar(c, output);
	}
}

int my_printf(char *str, int output, ...)
{
	va_list ap;

	va_start(ap, output);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != '%')
			my_putchar(str[i], output);
		else {
			which_flag(str[i + 1], ap, output);
			i++;
		}
		if (str[i] == '\0')
			i--;
	}
	va_end(ap);
	return (0);
}
