/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *s1, char *s2)
{
	int length = my_strlen(s1) + my_strlen(s2);
	char *res = malloc(sizeof(char) * (length + 1));
	int compt = 0;

	for (int i = 0; s1 && s1[i] != '\0'; i++, compt++)
		res[compt] = s1[i];
	for (int i = 0; s2 && s2[i] != '\0'; i++, compt++)
		res[compt] = s2[i];
	res[compt] = '\0';
	free(s1);
	free(s2);
	return (res);
}
