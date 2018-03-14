/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** game.c
*/

#include "my.h"
#include "navy.h"

int is_coord(char *enter)
{
	if (!enter)
		return (0);
	if (my_strlen(enter) != 2 || enter[0] < 'A' ||
	enter[0] > 'H' || enter[1] < '1' || enter[1] > '8') {
		my_putstr("wrong position\nattack: ", 1);
		return (0);
	}
	return (1);
}

void my_turn(info_t *board)
{
	int fire = 0;
	char *enter = NULL;
	int res;

	my_putstr("attack: ", 1);
	for (; is_coord(enter) == 0; enter = get_next_line(0)) {
		free(enter);
		usleep(60000);
	}
	fire += (enter[0] - 'A') + 10 * (enter[1] - '1');
	send(board->en_pid, fire);
	res = receive(board->en_pid);
	if (res == 0) {
		board->en_map[fire / 10][fire % 10] = 'o';
		my_printf("%s: missed\n\n", 1, enter);
	} else {
		board->hit++;
		board->en_map[fire / 10][fire % 10] = 'x';
		my_printf("%s: hit\n\n", 1, enter);
	}
}

void en_turn(info_t *board)
{
	int fire = 0;

	my_printf("waiting for enemy's attack...\n", 1);
	fire = receive(board->en_pid);
	my_printf("%c%d: ", 1, fire % 10 + 'A', fire / 10 + 1);
	if (board->my_map[fire / 10][fire % 10] > '5'
	|| board->my_map[fire / 10][fire % 10] < '2') {
		board->my_map[fire / 10][fire % 10] = 'o';
		my_putstr("missed\n\n", 1);
		send(board->en_pid, 0);
	} else {
		board->my_map[fire / 10][fire % 10] = 'x';
		my_putstr("hit\n\n", 1);
		send(board->en_pid, 1);
	}
}

int is_ended(info_t *board)
{
	int touched = 0;

	for (int i = 0; i < 8; i++) {
		touched += nb_occ(board->my_map[i], '2');
		touched += nb_occ(board->my_map[i], '3');
		touched += nb_occ(board->my_map[i], '4');
		touched += nb_occ(board->my_map[i], '5');
        }
	if (touched == 0)
		return (2);
	if (board->hit == 14)
		return (1);
	return (0);
}

int game(int ac, info_t *board)
{
	int play = 0;

	print_game(board);
	for (play = 0; play == 0;) {
		if (ac - 1 == 1)
			my_turn(board);
		else
			en_turn(board);
		play = is_ended(board);
		if (play == 0 && ac - 1 == 2)
			my_turn(board);
		else if (play == 0)
			en_turn(board);
		if (play == 0)
			play = is_ended(board);
		print_game(board);
	}
	my_printf("%s\n", 1, play == 1 ? "I won" : "Enemy won");
	return (play == 1 ? 0 : 1);
}
