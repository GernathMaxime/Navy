/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** ncurse_mode
*/

#include "my.h"
#include "navy.h"

static int fd = 0;

void join_getched(int nb, int *select, int *j, int max)
{
	static char address[14];
	static char port[14];
	static int address_compt = 0;
	static int port_compt = 0;

	if (nb == KEY_LEFT && (*select) > 0)
		(*select)--;
	else if (nb == KEY_RIGHT && (*select) < max)
		(*select)++;
	if (nb == 10 && (*select) == 3)
		(*j) = -5;
	if (nb == 10 && (*select) == 2) {
		fd = connect_to_server(my_atoi(port), address);
		if (fd != -1)
			(*j) = -5;
	}
	if (nb == 10 && (*select) == 0)
		enter_word("PORT", port, &port_compt);
	else if (nb == 10 && (*select) == 1)
		enter_word("IP", address, &address_compt);
}

void host_getched(int nb, int *select, int *j, int max)
{
	static char port[14];
	static int port_compt = 0;

	if (nb == KEY_LEFT && (*select) > 0)
		(*select)--;
	else if (nb == KEY_RIGHT && (*select) < max)
		(*select)++;
	if (nb == 10 && (*select) == 2)
		(*j) = -5;
	if (nb == 10 && (*select) == 1) {
		fd = create_server(my_atoi(port));
		if (fd != -1) {
			fd = accept_client(fd, 3);
			(*j) = -5;
		}
	}
	if (nb == 10 && (*select) == 0)
		enter_word("PORT", port, &port_compt);
}

int init_joiner(info_t *info)
{
	char **menu = str_to_tab(my_strdup("PORT IP PLAY EXIT"));
	int choice = 0;

	info->joiner = 1;
	for (int j = 0; j >= 0;) {
		clear();
		for (int i = 0; i < my_strlen(menu[choice]); i++) {
			j = COLS / 2 - 15 + choice * 10 + i;
			mvprintw(LINES / 2 - 2, j, "_");
			mvprintw(LINES / 2 + 1, j, "_");
		}
		for (int i = 0; i < 4; i++)
			mvprintw(LINES / 2, COLS / 2 - 15 + i * 10, menu[i]);
		join_getched(getch(), &choice, &j, 3);
		refresh();
	}
	info->fd = fd;
	my_strstrfree(menu);
	return (choice == 3 ? 2 : 1);
}

int init_host(info_t *info)
{
	char **menu = str_to_tab(my_strdup("PORT PLAY EXIT"));
	int choice = 0;

	info->joiner = 0;
	for (int j = 0; j >= 0;) {
		clear();
		endwin();
		mvprintw(LINES / 2 + 5, COLS / 2 - 6, getip());
		for (int i = 0; i < my_strlen(menu[choice]); i++) {
			j = COLS / 2 - 10 + choice * 10 + i;
			mvprintw(LINES / 2 - 2, j, "_");
			mvprintw(LINES / 2 + 1, j, "_");
		}
		for (int i = 0; i < 3; i++)
			mvprintw(LINES / 2, COLS / 2 - 10 + i * 10, menu[i]);
		host_getched(getch(), &choice, &j, 2);
		refresh();
	}
	info->fd = fd;
	my_strstrfree(menu);
	return (choice == 2 ? 2 : 0);
}

int init_online(info_t *info)
{
	char **menu = str_to_tab(my_strdup("HOST CLIENT EXIT"));
	int choice = 0;

	for (int j = 0; j >= 0;) {
		clear();
		for (int i = 0; i < my_strlen(menu[choice]); i++) {
			j = COLS / 2 - 10 + choice * 10 + i;
			mvprintw(LINES / 2 - 2, j, "_");
			mvprintw(LINES / 2 + 1, j, "_");
		}
		for (int i = 0; i < 3; i++)
			mvprintw(LINES / 2, COLS / 2 - 10 + i * 10, menu[i]);
		get_getched(getch(), &choice, &j, 2);
		refresh();
	}
	my_strstrfree(menu);
	choice == 0 ? choice = init_host(info) : 0;
	choice == 1 ? choice = init_joiner(info) : 0;
	return (choice == 2 ? -1 : 0);
}
