/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** chose_shot.c
*/

#include "my.h"
#include "navy.h"

char **get_map(info_t *in, int nb, int fd)
{
	char **en_map = malloc(sizeof(char *) * 8);

	for (int j = 1; j < 3; j++) {
		for (int i = 0; i < 8; i++) {
			nb == j ? write(fd, in->my_map[i], 8) : 0;
			nb != j ? en_map[i] = malloc(sizeof(char) * 9) : 0;
			nb != j ? read(fd, en_map[i], 8) : 0;
			nb != j ? en_map[8] = '\0' : 0;
		}
	}
	return (en_map);
}

static void manage_getch(int nb, int *chose, int *j, int *game)
{
	nb == KEY_DOWN && (*chose) < 70 ? (*chose) += 10 : 0;
	nb == KEY_UP && (*chose) > 9 ? (*chose) -= 10 : 0;
	nb == KEY_LEFT && (*chose) % 10 > 0 ? (*chose) -= 1 : 0;
	nb == KEY_RIGHT && (*chose) % 10 < 7 ? (*chose) += 1 : 0;
	nb == 10 ? (*j) = -5 : 0;
	nb == 27 ? (*j) = -5 : 0;
	nb == 27 ? (*game) = -5 : 0;
}

int chose_shot(info_t *in, int *game)
{
	static int chose = 0;

	for (int j = 0; j == 0;) {
		clear();
		draw_maps(in->my_map, in->en_map);
		mvprintw(LINES / 2 - 9 + chose / 10,
		COLS / 2 - 7 + 2 * (chose % 10), "+");
		refresh();
		manage_getch(getch(), &chose, &j, game);
	}
	return (chose);
}
