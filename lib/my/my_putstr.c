/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_putstr
*/

#include "my.h"

void my_printf_str(va_list ap, int output)
{
	my_putstr(va_arg(ap, char*), output);
}

void my_putstr(char *str, int sortie)
{
	write(sortie, str, my_strlen(str));
}
