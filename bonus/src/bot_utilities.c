/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** bot_utilities.c
*/

#include "my.h"
#include "navy.h"

static int finished(char **map, int i, int j)
{
	if ((i == 0 || map[i - 1][j] == 'o' || map[i - 1][j] == 'x') &&
	(i == 7 || map[i + 1][j] == 'o' || map[i + 1][j] == 'x') &&
	((i == 0 || map[i - 1][j] != 'o') || (i == 7 || map[i + 1][j] != 'o')))
		return (-1);
	if ((j == 0 || map[i][j - 1] == 'o' || map[i][j - 1] == 'x') &&
	(j == 7 || map[i][j + 1] == 'o' || map[i][j + 1] == 'x') &&
	((j == 0 || map[i][j - 1] != 'o') || (j == 7 || map[i][j + 1] != 'o')))
		return (-1);
	return (0);
}

static int rand_square(char **map, int i, int j)
{
	int nb = 0;

	if (finished(map, i, j) == -1)
		return (-1);
	i > 0 && map[i - 1][j] == '.' ? nb++ : 0;
	i < 7 && map[i + 1][j] == '.' ?	nb++ : 0;
	j > 0 && map[i][j - 1] == '.' ? nb++ : 0;
	j < 7 && map[i][j + 1] == '.' ? nb++ : 0;
	if (nb == 0)
		return (-1);
	nb = rand() % nb + 1;
	if (i > 0 && map[i - 1][j] == '.' && nb-- == 1)
		return ((i - 1) * 10 + j);
	if (i < 7 && map[i + 1][j] == '.' && nb-- == 1)
		return ((i + 1) * 10 + j);
	if (j > 0 && map[i][j - 1] == '.' && nb-- == 1)
		return (i * 10 + j - 1);
	if (j < 7 && map[i][j + 1] == '.' && nb == 1)
		return (i * 10 + j + 1);
	return (-1);
}

static int check_slot(char **map, int i, int j)
{
	if (i < 7 && i > 0 && map[i + 1][j] == 'x' && map[i - 1][j] == '.')
		return ((i - 1) * 10 + j);
	if (i < 7 && i > 0 && map[i - 1][j] == 'x' && map[i + 1][j] == '.')
		return ((i + 1) * 10 + j);
	if (j < 7 && j > 0 && map[i][j + 1] == 'x' && map[i][j - 1] == '.')
		return (i * 10 + j - 1);
	if (j < 7 && j > 0 && map[i][j - 1] == 'x' && map[i][j + 1] == '.')
		return (i * 10 + j + 1);
	return (-1);
}

int focus_boat(char **map)
{
	int nb = -1;

	for (int i = 0; i < 8 && nb == -1; i++)
		for (int j = 0; j < 8 && nb == -1; j++)
			nb = map[i][j] == 'x' ? check_slot(map, i, j) : -1;
	for (int i = 0; i < 8 && nb == -1; i++)
		for (int j = 0; j < 8 && nb == -1; j++)
			nb = map[i][j] == 'x' ? rand_square(map, i, j) : -1;
	return (nb);
}

int take_random(char **map)
{
	int nb = 0;
	int i = 0;
	int j = 0;

	for (; i < 8; i++)
		nb += nb_occ(map[i], '.');
	nb = rand() % nb + 1;
	for (i = 0; i < 8 && nb > 0; i++)
		for (j = 0; j < 8 && nb > 0; j++)
			nb > 0 && map[i][j] == '.' ? nb-- : 0;
	return ((i - 1) * 10 + j - 1);
}
