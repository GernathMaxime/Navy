/*
** EPITECH PROJECT, 2018
** last_utilities
** File description:
** bonuce
*/

#include "my.h"
#include "navy.h"

void getch_me(char *str, int *place, int nb, int *j)
{
	if (nb == 10)
		(*j) = -5;
	else if (nb == KEY_BACKSPACE) {
		str[*place] = '\0';
		(*place)--;
	} else {
		if (*place < 13) {
			str[*place] = nb;
			(*place)++;
		}
	}
}

void enter_word(char *draw, char *str, int *place)
{
	for (int j = 0; j >= 0;) {
		clear();
		mvprintw(LINES / 2 - 2, COLS / 2 - my_strlen(draw) / 2, draw);
		mvprintw(LINES / 2, COLS / 2 - my_strlen(str) / 2, str);
		getch_me(str, place, getch(), &j);
		refresh();
	}
}

char *getip(void)
{
	sfIpAddress my_ip = sfIpAddress_getLocalAddress();
	char *ip = malloc(sizeof(char) * 100);

	sfIpAddress_toString(my_ip, ip);
	return (ip);
}

void ended_scree(int nb, info_t *in, int fd)
{
	char *res = nb == 1 ? "YOU LOSE" : "YOU WIN";
	char **en_map = NULL;

	if (nb == 0)
		return;
	en_map = get_map(in, nb, fd);
	for (int j = 0; j == 0;) {
		clear();
		mvprintw(LINES / 2 - 7, COLS / 2 - (my_strlen(res) / 2), res);
		mvprintw(LINES / 2 - 1, COLS / 2 - 10, " | A B C D E F G H");
		mvprintw(LINES / 2, COLS / 2 - 10, "-+----------------");
		draw_map(en_map, 1);
		refresh();
		get_escape(getch(), &j);
	}
}

int is_ende(info_t *info)
{
	int nb = 0;

	for (int i = 0; i < 8; i++)
		nb += nb_occ(info->en_map[i], 'x');
	if (nb == 14)
		return (2);
	nb = 0;
	for (int i = 0; i < 8; i++) {
		nb += nb_occ(info->my_map[i], '2');
		nb += nb_occ(info->my_map[i], '3');
		nb += nb_occ(info->my_map[i], '4');
		nb += nb_occ(info->my_map[i], '5');
	}
	if (nb == 0)
		return (1);
	return (0);
}
