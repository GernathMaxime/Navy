/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char *s1, char *s2)
{
	if (my_strlen(s1) > my_strlen(s2))
		return (1);
	else if (my_strlen(s1) < my_strlen(s2))
		return (-1);
	for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
	}
	return (0);
}
