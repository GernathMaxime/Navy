/*
** EPITECH PROJECT, 2018
** lib
** File description:
** return the number of c in str
*/

#include "my.h"

int nb_occ(char *str, char c)
{
	int nb = 0;

	for (int i = 0; str[i]; i++)
		if (str[i] == c)
			nb++;
	return (nb);
}
