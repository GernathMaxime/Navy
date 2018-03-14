/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** advancer_bot.c
*/

#include "my.h"
#include "navy.h"

int random_corner(void)
{
	int nb = rand() % 4;

	if (nb == 0)
		return (0);
	if (nb == 1)
		return (77);
	if (nb == 2)
		return (70);
	return (7);
}

int take_smaller(char **map)
{
	int res = 5;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			res = map[i][j] != '.' && map[i][j] - '0' < res ?
			map[i][j] - '0' : res;
	return (res);
}

int take_random_point(char **map)
{
	int nb_res = 0;
	int i = 0;
	int j = 0;

	for (int i = 0; i < 8; i++)
		nb_res += nb_occ(map[i], '.');
	if (nb_res == 64)
		return (-1);
	if (nb_res == 63)
		return (-2);
	nb_res = rand() % (64 - nb_res) + 1;
	for (; i < 8 && nb_res > 0; i++)
		for (j = 0; j < 8 && nb_res > 0; j++)
			map[i][j] != '.' ? nb_res-- : 0;
	return ((i - 1) * 10 + j - 1);
}

int next_smart(char **map, int min, int start)
{
	int i = 0;

	for (i = start / 10 + min; i > start / 10 && i < 8; i--)
		if (map[i][start % 10] != '.')
			break;
	if (i == start / 10)
		return (start + min * 10);

	for (i = start % 10 - min; i < start % 10 && i >= 0; i++)
		if (map[start / 10][i] != '.')
			break;
	if (i == start % 10)
		return (start - min);
	for (i = start % 10 + min; i > start % 10 && i < 8; i--)
		if (map[start / 10][i] != '.')
			break;
	if (i == start % 10)
		return (start + min);
	return (-1);
}

int smart_move(char **map, int min, int start)
{
	int i = 0;

	if (start == -1)
		return (random_corner());
	if (start == -2)
		return (diago(map));
	for (i = start / 10 - min; i < start / 10 && i >= 0; i++)
		if (map[i][start % 10] != '.')
			break;
	if (i == start / 10)
		return (start - min * 10);
	return (next_smart(map, min, start));
}
