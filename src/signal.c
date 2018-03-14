/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** signal
*/

#include "my.h"
#include "navy.h"

void handle_pid(int signal, siginfo_t *info, void *trash)
{
	bit = info->si_pid;
	trash = &signal;
	trash++;
}

void handle(int signal, siginfo_t *info, void *trash)
{
	if (signal == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	trash = info;
	trash++;
}

void recup_pid(int ac, char **av, info_t *board)
{
	if (ac == 3) {
		my_printf("my_pid: %d\n", 1, board->my_pid);
		board->en_pid = my_atoi(av[1]);
		kill(board->en_pid, SIGUSR1);
		my_printf("succesfully connected\n\n", 1);
	} else {
		my_printf("my_pid: %d\n", 1, board->my_pid);
		my_printf("waiting for enemy connection...\n", 1);
		while (bit == -1);
		board->en_pid = bit;
		bit = -1;
		my_printf("\nenemy connected\n\n", 1);
	}
}

int receive(int pid)
{
	char *number = malloc(sizeof(char) * 33);
	int res = 0;

	if (!number)
		return (0);
	number[32] = '\0';
	for (int i = 31; i >= 0; i--) {
		usleep(900);
		kill(pid, SIGUSR1);
		while (bit == -1);
		number[i] = bit + '0';
		bit = -1;
	}
	res = convert_bin(number, 0);
	free(number);
	return (res);
}

void send(int pid, int nb)
{
	for (int i = 0; i < 32; i++) {
		while (bit == -1);
		if (((nb >> i) & 1) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit = -1;
	}
}
