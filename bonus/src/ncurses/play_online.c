/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** play_online.c
*/

#include "navy.h"
#include "my.h"

static int fd;

void apply_mapp(char **reference, char **target, int nb, music_t *music)
{
	char c = 'x';

	if ((reference[nb / 10][nb % 10] < '2'
	|| reference[nb / 10][nb % 10] > '5')
	&& reference[nb / 10][nb % 10] != 'x') {
		c = 'o';
		sfMusic_play(music->missed);
		write(fd, "00", 2);
	} else {
		sfMusic_play(music->touched);
		write(fd, "01", 2);
	}
	target[nb / 10][nb % 10] = c;
}

void apply_ma(char **map, int pos, int res, music_t *music)
{
	if (res == 1) {
		map[pos / 10][pos % 10] = 'x';
		sfMusic_play(music->touched);
	} else {
		sfMusic_play(music->missed);
		map[pos / 10][pos % 10] = 'o';
	}
}

void victim_turn(info_t *in)
{
	char *str = malloc(sizeof(char) * (2 + 1));
	int shot = 0;

	str[2] = '\0';
	read(fd, str, 2);
	shot = my_atoi(str);
	apply_mapp(in->my_map, in->my_map, shot, in->music);
}

void sniper_turn(info_t *in, int *j)
{
	int shot = 0;
	char *str = NULL;

	shot = chose_shot(in, j);
	str = my_itoa(shot);
	if (shot < 10)
		str = my_strcat(my_chardup('0'), str);
	write(fd, str, 2);
	read(fd, str, 2);
	apply_ma(in->en_map, shot, my_atoi(str), in->music);
}


void play_online(info_t *in)
{
	int turn = in->joiner;

	fd = in->fd;
	for (int j = 0; j == 0 && is_ende(in) == 0; turn++) {
		clear();
		draw_maps(in->my_map, in->en_map);
		refresh();
		if (turn % 2 == 0)
			victim_turn(in);
		else
			sniper_turn(in, &j);
	}
	ended_scree(is_ende(in), in, fd);
}
