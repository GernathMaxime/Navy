/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "my.h"
#include "navy.h"

void print_usage(void)
{
	my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n", 1);
	my_putstr("DESCRIPTION\n\tfirst_player_pid: only for", 1);
	my_putstr(" the 2nd player. pid of the first player.\n\tnavy_", 1);
	my_putstr("positions: file representing ", 1);
	my_putstr("the positions of the ships.\n", 1);
}

int init_game(info_t *board, int ac, char **av)
{
	struct sigaction test;

	test.sa_sigaction = &handle_pid;
	test.sa_flags = SA_SIGINFO;
	sigemptyset(&test.sa_mask);
	sigaction(SIGUSR1, &test, NULL);
	sigaction(SIGUSR2, &test, NULL);
	if (fill_board(board, ac, av) != 0)
		return (-1);
	test.sa_sigaction = &handle;
	sigaction(SIGUSR1, &test, NULL);
	sigaction(SIGUSR2, &test, NULL);
	return (0);
}

int main(int ac, char **av)
{
	info_t *board = malloc(sizeof(*board));

	if (av[1] && my_strcmp(av[1], "-h") == 0) {
		print_usage();
		return (0);
	}
	bit = -1;
	if (init_game(board, ac, av) < 0)
		return (84);
	return (game(ac, board));
}
