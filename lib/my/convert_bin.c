/*
** EPITECH PROJECT, 2018
** lib
** File description:
** convert binary to dec order = 0 is real, if = 1 it's reversed
*/

#include "my.h"

int convert_bin(char *number, int order)
{
	int res = 0;
	int puis = 1;

	if (!number || my_strlen(number) != 32)
		return (0);
	if (order == 1)
		my_revstr(number);
	for (int i = 31; i > 0; i--) {
		if (i != 31)
			puis *= 2;
		res += puis * (number[i] - '0');
	}
	if (number[0] == '1')
		res = res * -1;
	return (res);
}
