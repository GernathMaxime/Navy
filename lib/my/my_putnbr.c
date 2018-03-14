/*
** EPITECH PROJECT, 2017
** my priintf
** File description:
** my_putnbr
*/

#include "my.h"

void my_printf_nbr(va_list ap, int output)
{
	my_putnbr(va_arg(ap, int), output);
}

int my_putnbr(long nb, int output)
{
	if (nb < 0) {
		my_putchar('-', output);
		my_putnbr(nb * (-1), output);
	} else {
		if (nb < 10) {
			my_putchar(nb + '0', output);
		} else {
			my_putnbr(nb / 10, output);
			my_putchar(nb % 10 + '0', output);
		}
	}
	return (0);
}
