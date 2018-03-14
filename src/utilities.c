/*
** EPITECH PROJECT, 2018
** navy
** File description:
** utilities.c
*/

#include "my.h"
#include "navy.h"

int fill_board(info_t *board, int ac, char **av)
{
	if (!board || !(board->my_map = check_start(ac, av)))
		return (84);
	board->my_map = create_map(board->my_map);
	board->en_map = empty_map();
	if (!board->my_map || !board->en_map)
		return (84);
	board->my_pid = getpid();
	board->hit = 0;
	recup_pid(ac, av, board);
	return (0);
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

void print_map(char **map)
{
	char c = '1';

	my_putstr(" |A B C D E F G H\n", 1);
	my_putstr("-+---------------\n", 1);
	for (int i = 0; i < 8; i++, c++) {
		my_putchar(c, 1);
		my_putchar('|', 1);
		for (int j = 0; j < 8; j++) {
			my_putchar(map[i][j], 1);
			my_putchar(map[i][j + 1] ? ' ' : '\n', 1);
		}
	}
	my_putchar('\n', 1);
}

void print_game(info_t *board)
{
	my_putstr("my_positions:\n", 1);
	print_map(board->my_map);
	my_putstr("enemy's positions:\n", 1);
	print_map(board->en_map);
}
