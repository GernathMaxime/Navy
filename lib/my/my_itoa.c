/*
** EPITECH PROJECT, 2017
** bistro-maitc
** File description:
** my_itoa
*/

#include "my.h"

static int nb_letters(int nb)
{
	int compt = 1;

	if (nb < 0) {
		nb = (-1 * nb);
		compt++;
	}
	while ((nb / 10) > 0) {
		compt++;
		nb = nb / 10;
	}
	return (compt);
}

char *my_itoa(int nb)
{
	int len = (nb_letters(nb) + 1);
	char *str = malloc(sizeof(char) * len);
	int stash = 1;

	if (nb < 0) {
		nb = (-1 * nb);
		str[len - 2] = '-';
		stash = 2;
	}
	for (int i = 0; i < len - stash; i++) {
		str[i] = (nb % 10) + 48;
		nb = nb / 10;
	}
	str[len - 1] = '\0';
	return (my_revstr(str));
}
