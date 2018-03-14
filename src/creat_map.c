/*
** EPITECH PROJECT, 2018
** creat_map.c
** File description:
** creat_map
*/

#include "my.h"
#include "navy.h"
#include <unistd.h>

char **empty_map(void)
{
	char **map = malloc(sizeof(char *) * 9);

	if (!map)
		return (NULL);
	map[8] = NULL;
	for (int i = 0; i < 8; i++) {
		map[i] = malloc(sizeof(char) * 9);
		if (!map[i])
			return (NULL);
		map[i][8] = '\0';
		for (int j = 0; j < 8; j++)
			map[i][j] = '.';
	}
	return (map);
}

int fill_map(char **map, char **pos)
{
	coord_t *ship = NULL;

	for (int i = 0; i < 4; i++) {
		ship = get_coord(pos[i]);
		if (!ship || add_ship(map, ship, pos[i][0]) == -1)
			return (-1);
		free(ship);
	}
	return (0);
}

char **create_map(char **pos)
{
	char **map = empty_map();

	if (!map)
		return (NULL);
	if (fill_map(map, pos) == -1)
		return (NULL);
	my_strstrfree(pos);
	return (map);
}
