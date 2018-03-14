/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** bot_map.c
*/

#include "my.h"
#include "navy.h"

int place_ship(char **map, int length, int *x, int *y)
{
	int pos = rand() % 64 + 1;

	if (rand() % 2 == 0) {
		*y = 0;
		*x = rand() % 2 == 1 ? 1 : -1;
	} else {
		*y = rand() % 2 == 1 ? 1 : -1;
		*x = 0;
	}
	if (pos / 10 + length * (*x) > 7 || pos / 10 + length * (*x) < 0 ||
	    pos % 10 + length * (*y) > 7 || pos % 10 + length * (*y) < 0)
		return (-1);
	for (int j = 0; j < length; j++)
		if (map[pos / 10 + j * (*x)][pos % 10 + j * (*y)] != '.')
			return (-1);
	return (pos);
}

char **bot_map_create(void)
{
	char **map = empty_map();
	int x = 0;
	int y = 0;
	int pos = 0;

	for (int i = 2; i < 6; i++) {
		while ((pos = place_ship(map, i, &x, &y)) < 0);
		for (int j = 0; j < i; j++)
			map[pos / 10 + j * x][pos % 10 + j * y] = i + '0';
	}
	return (map);
}
