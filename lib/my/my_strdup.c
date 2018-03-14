/*
** EPITECH PROJECT, 2017
** bistro-matic
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char *src)
{
	int size = my_strlen(src);
	char *str = malloc(sizeof(char) * size + 1);

	for (int i = 0; i < size; i++)
		str[i] = src[i];
	str[size] = '\0';
	return (str);
}
