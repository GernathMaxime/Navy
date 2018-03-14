/*
** EPITECH PROJECT, 2018
** lib
** File description:
** verify if the string given as parameter is a int between min and max
*/

#include "my.h"

static int too_big(char *nb)
{
	char *highest = "2147483647";

	if (nb[0] == '-') {
		nb++;
		highest = "2147483648";
	}
	if (my_strlen(nb) > 10)
		return (84);
	if (my_strlen(nb) < 10)
		return (0);
	for (int i = 0; i < 10; i++) {
		if (nb[i] < highest[i])
			return (0);
		else if (nb[i] > highest[i])
			return (84);
	}
	return (0);
}

int is_int_in(char *nbr, int min, int max)
{
	int nb = 0;

	if (!nbr)
		return (84);
	for (int i = 0; nbr[i] != '\0'; i++) {
		if ((nbr[i] > '9' || nbr[i] < '0') && nbr[i] != '-')
			return (84);
		if (nbr[i] == '-' && i != 0)
			return (84);
	}
	if (too_big(nbr))
		return (84);
	nb = my_atoi(nbr);
	if (nb < min || nb > max)
		return (84);
	return (0);
}
