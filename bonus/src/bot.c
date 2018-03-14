/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** bot.c
*/

#include "my.h"
#include "navy.h"

int diago(char **map)
{
	if (map[0][0] != '.')
		return (11);
	if (map[7][7] != '.')
		return (66);
	if (map[7][0] != '.')
		return (61);
	return (16);
}

int bot2(char **map)
{
	int nb = focus_boat(map);

	return (nb == -1 ? take_random(map) : nb);
}

int bot3(char **map, char **cheat)
{
	int nb = focus_boat(map);
	int min = 0;

	if (nb != -1)
		return (nb);
	min = take_smaller(cheat);
	for (int i = 0; i < 10000 && nb == -1; i++) {
		nb = take_random_point(map);
		nb = smart_move(map, min, nb);
	}
	return (nb == -1 ? take_random(map) : nb);
}

int bot4(char **map, char **cheat)
{
	int nb = focus_boat(map);
	int len = 0;

	if (nb != -1)
		return (nb);
	nb = bot3(map, cheat);
	for (int i = 0; i < 8; i++)
		len += nb_occ(map[i], 'o');
	if (len > 3 && rand() % 100 > 50) {
		while (cheat[nb / 10][nb % 10] == '.')
			nb = take_random(map);
	}
	return (nb);
}
