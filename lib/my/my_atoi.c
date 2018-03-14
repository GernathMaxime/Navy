/*
** EPITECH PROJECT, 2017
** bistro-matic
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char *str)
{
	int result = 0;
	int sign = 1;

	if (str[0] == '-') {
		sign = -1;
		str++;
	}
	for (int i = 0; str[i] != '\0'; i++)
		result = result * 10 + str[i] - '0';
	return (result * sign);
}
