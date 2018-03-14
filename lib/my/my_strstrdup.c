/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_strstrdup.c
*/

#include "my.h"

char **my_strstrdup(char **str)
{
	int len = 0;
	char **res = NULL;

	for (; str[len]; len++);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = NULL;
	for (int i = 0; str[i]; i++) {
		res[i] = malloc(sizeof(char) * (my_strlen(str[i]) + 1));
		for (len = 0; str[i][len]; len++)
			res[i][len] = str[i][len];
		res[i][len] = '\0';
	}
	return (res);
}
