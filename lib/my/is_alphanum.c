/*
** EPITECH PROJECT, 2018
** lib
** File description:
** verify if a string contain only letters and numbers
*/

#include "my.h"

int is_alphanum(char *str)
{
	for (int i = 0; str[i]; i++) {
		if ((str[i] > 'Z' || str[i] < 'A') &&
		(str[i] > 'z' || str[i] < 'a') &&
		(str[i] > '9' || str[i] < '0'))
			return (84);
	}
	return (0);
}
