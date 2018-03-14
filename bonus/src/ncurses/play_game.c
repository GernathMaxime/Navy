/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** play_game.c
*/

#include "my.h"
#include "navy.h"

void ended_screen(int nb, info_t *info)
{
	char *res = nb == 1 ? "YOU LOSE" : "YOU WIN";

	if (nb == 0)
		return;
	for (int j = 0; j == 0;) {
		clear();
		mvprintw(LINES / 2 - 7, COLS / 2 - (my_strlen(res) / 2), res);
		mvprintw(LINES / 2 - 1, COLS / 2 - 10, " | A B C D E F G H");
		mvprintw(LINES / 2, COLS / 2 - 10, "-+----------------");
		draw_map(info->bot_map, 1);
		get_escape(getch(), &j);
		refresh();
	}
}

int is_ended(info_t *info)
{
	int nb = 0;

	for (int i = 0; i < 8; i++)
		nb += nb_occ(info->empty_map[i], 'x');
	if (nb == 14)
		return (1);
	nb = 0;
	for (int i = 0; i < 8; i++)
		nb += nb_occ(info->en_map[i], 'x');
	if (nb == 14)
		return (2);
	return (0);
}

void apply_map(char **reference, char **target, int nb, music_t *music)
{
	char c = 'x';

	if ((reference[nb / 10][nb % 10] < '2'
	|| reference[nb / 10][nb % 10] > '5')
	&& reference[nb / 10][nb % 10] != 'x') {
		c = 'o';
		sfMusic_play(music->missed);
	} else
		sfMusic_play(music->touched);
	target[nb / 10][nb % 10] = c;
}

int bot(info_t *info)
{
	int nb = 0;

	switch (info->difficulty) {
	case 1:
		nb = bot2(info->empty_map);
		break;
	case 2:
		nb = bot3(info->empty_map, info->my_map);
		break;
	case 3:
		nb = bot4(info->empty_map, info->my_map);
		break;
	default:
		nb = take_random(info->empty_map);
		break;
	}
	return (nb);
}

void play_game(info_t *in)
{
	int choice = 0;
	int select = 0;

	for (int j = 0; j != -5 && is_ended(in) == 0; j++) {
		clear();
		draw_maps(in->my_map, in->en_map);
		if (j % 2 == 0) {
			mvprintw(LINES / 2 - 9 + select / 10,
			COLS / 2 - 7 + 2 * (select % 10), "+");
			refresh();
			select = human(in, &j);
		} else {
			refresh();
			usleep(450000);
			choice = bot(in);
			apply_map(in->my_map, in->empty_map, choice, in->music);
			apply_map(in->my_map, in->my_map, choice, in->music);
		}
	}
	ended_screen(is_ended(in), in);
}
