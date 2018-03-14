/*
** EPITECH PROJECT, 2017
** bistro_matic
** File description:
** my_chardup
*/

#include "my.h"

char *my_chardup(char c)
{
	char *res = malloc(sizeof(char) * 2);

	res[0] = c;
	res[1] = '\0';
	return (res);
}
