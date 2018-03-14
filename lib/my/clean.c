/*
** EPITECH PROJECT, 2018
** lib
** File description:
** remove space and tabs from a line ("" are taken)
*/

#include "my.h"

static void fill_res(char *str, char *res, int nb)
{
	int i = 0;
	int dot = 0;

	for (; str[nb] != '\0'; nb++) {
		if (str[nb] == '"')
			dot = (dot == 1 ? 0 : 1);
		if (dot == 1 || (str[nb] != ' ' && str[nb] != '\t')) {
			res[i] = str[nb];
			i++;
		} else if (str[nb + 1] != ' ' && str[nb + 1] != '\t'
			&& str[nb + 1] != '\0') {
			res[i] = str[nb];
			i++;
		}
	}
	res[i] = '\0';
}

char *clean(char *str)
{
	int len = 0;
	char *res = NULL;
	int nb = 0;

	if (!str)
		return (NULL);
	len = my_strlen(str);
	res = malloc(sizeof(char) * (1 + len));
	for (; str[nb] == ' ' || str[nb] == '\t'; nb++);
	fill_res(str, res, nb);
	free(str);
	return (res);
}
