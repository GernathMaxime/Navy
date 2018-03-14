/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_getnbr
*/

#include "my.h"

long my_getnbr(char *str)
{
	long nb = 0;
	int sign = 1;
	int i = 0;

	if (!str)
		return (0);
	for (; str[i] && (str[i] > '9' || str[i] < '0'); i++);
	if (!str[i])
		return (0);
	for (; i > 0 && (str[i - 1] == '-' || str[i - 1] == '+'); i--);
	for (; str[i] && (str[i] == '-' || str[i] == '+'); i++)
		if (str[i] == '-')
			sign *= -1;
	for (; str[i] && str[i] >= '0' && str[i] <= '9'; i++)
		nb = nb * 10 + (str[i] - '0');
	return (sign * nb);
}
