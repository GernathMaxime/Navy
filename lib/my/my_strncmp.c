/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_strncmp
*/

#include "my.h"

int my_strncmp(char *s1, char *s2, int nb)
{
	int ls1 = my_strlen(s1);
	int ls2 = my_strlen(s2);

	if (ls1 < nb || ls2 < nb)
		return (ls1 - ls2);
	for (int i = 0; i != nb; i++) {
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
	}
	return (0);
}
