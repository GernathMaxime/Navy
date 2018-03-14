/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** utilities.c
*/

#include "my.h"
#include "navy.h"

void get_getched(int nb, int *select, int *j, int max)
{
	if (nb == KEY_LEFT && (*select) > 0)
		(*select)--;
	else if (nb == KEY_RIGHT && (*select) < max)
		(*select)++;
	if (nb == 10)
		(*j) = -5;
}

void get_escape(int nb, int *j)
{
	if (nb == 10)
		(*j) = -6;
}

void draw_map(char **map, int start)
{
	int cols = -8;
	char *str = NULL;

	for (int i = 0; i < 8; i++, cols = -8, start++) {
		str = my_chardup(i + '1');
		mvprintw(LINES / 2 + start, COLS / 2 - 10, str);
		free(str);
		mvprintw(LINES / 2 + start, COLS / 2 - 9, "|");
		for (int j = 0; j < 8; j++, cols += 2) {
			str = my_chardup(map[i][j]);
			map[i][j] == 'x' ? attron(COLOR_PAIR(1)) : 0;
			map[i][j] == 'o' ? attron(COLOR_PAIR(2)) : 0;
			mvprintw(LINES / 2 + start, COLS / 2 + cols + 1, str);
			map[i][j] == 'o' ? attroff(COLOR_PAIR(1)) : 0;
			map[i][j] == 'x' ? attroff(COLOR_PAIR(2)) : 0;
			mvprintw(LINES / 2 + start, COLS / 2 + cols, " ");
			free(str);
		}
	}
}

void draw_maps(char **my, char **en)
{
	mvprintw(LINES / 2 - 11, COLS / 2 - 10, " | A B C D E F G H");
	mvprintw(LINES / 2 - 10, COLS / 2 - 10, "-+----------------");
	mvprintw(LINES / 2 + 1, COLS / 2 - 10, " | A B C D E F G H");
	mvprintw(LINES / 2 + 2, COLS / 2 - 10, "-+----------------");
	draw_map(en, -9);
	draw_map(my, 3);
}
