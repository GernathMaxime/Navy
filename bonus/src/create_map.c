/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** create_map.c
*/

#include "my.h"
#include "navy.h"

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

coord_t *get_coord(char *coord)
{
	coord_t *res = malloc(sizeof(coord_t) * (coord[0] - '0' + 1));
	int nb = coord[2] == coord[5] ? 3 : 2;

	if (!res)
		return (NULL);
	res[coord[0] - '0'].x = -84;
	for (int i = 0; i != coord[0] - '0'; i++) {
		res[i].x = coord[3] - '1';
		res[i].y = coord[2] - 'A';
		coord[nb] += 1;
	}
	return (res);
}

int add_ship(char **map, coord_t *ship, char length)
{
	for (int i = 0; ship[i].x != -84; i++) {
		if (map[ship[i].x][ship[i].y] != '.')
			return (-1);
		map[ship[i].x][ship[i].y] = length;
	}
	return (0);
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

char **create_map(char *file)
{
	char **pos = malloc(sizeof(char *) * 5);
	char **map = empty_map();
	int fd = open(file, O_RDONLY);
	int i = 0;

	if (!map || !pos || fd < 0)
		return (NULL);
	for (; i < 5 && (pos[i] = get_next_line(fd)); i++);
	if (i < 4 || pos[4])
		return (NULL);
	if (fill_map(map, pos) == -1)
		return (NULL);
	my_strstrfree(pos);
	return (map);
}
