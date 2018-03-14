/*
** EPITECH PROJECT, 2017
** my revstr
** File description:
** task03
*/

#include "my.h"

char *my_revstr(char *str)
{
	int length = my_strlen(str) - 1;
	char c;

	for (int i = 0; i < length; i++) {
		c = str[length];
		str[length] = str[i];
		str[i] = c;
		length = length - 1;
	}
	return (str);
}
