/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** lib
*/

#include "my.h"

void my_printf_char(va_list ap, int output)
{
	my_putchar(va_arg(ap, int), output);
}

void my_putchar(char c, int output)
{
	write(output, &c, 1);
}
