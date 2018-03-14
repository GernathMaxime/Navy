/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** ncurse_mode
*/

#include "my.h"
#include "navy.h"

int init_bot(info_t *info)
{
	char **menu = str_to_tab(my_strdup("NOOB EASY HARD HELL EXIT"));

	for (int j = 0; j >= 0;) {
		clear();
		for (int i = 0; i < my_strlen(menu[info->difficulty]); i++) {
			j = COLS / 2 - 20 + info->difficulty * 10 + i;
			mvprintw(LINES / 2 - 2, j, "_");
			mvprintw(LINES / 2 + 1, j, "_");
		}
		for (int i = 0; i < 5; i++)
			mvprintw(LINES / 2, COLS / 2 - 20 + i * 10, menu[i]);
		get_getched(getch(), &info->difficulty, &j, 4);
		refresh();
	}
	my_strstrfree(menu);
	return (info->difficulty == 4 ? -1 : 0);
}

int init_menu(info_t *info)
{
	int select = 0;
	char **menu = str_to_tab(my_strdup("ONLINE OFFLINE EXIT"));

	for (int j = 0; j >= 0;) {
		clear();
		for (int i = 0; i < my_strlen(menu[select]); i++) {
			j = COLS / 2 - 10 + select * 10 + i;
			mvprintw(LINES / 2 - 2, j, "_");
			mvprintw(LINES / 2 + 1, j, "_");
		}
		for (int i = 0; i < 3; i++)
			mvprintw(LINES / 2, COLS / 2 - 10 + i * 10, menu[i]);
		get_getched(getch(), &select, &j, 2);
		refresh();
	}
	my_strstrfree(menu);
	if (select == 0)
		info->online = 1;
	return (select == 2 ? -1 : select);
}

void init_curse(void)
{
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
}

void ncurses_mode(info_t *info)
{
	init_curse();
	if (init_menu(info) < 0)
		return;
	else if (info->online == 0) {
		info->bot_map = bot_map_create();
		info->empty_map = empty_map();
		if (init_bot(info) < 0)
			return;
		play_game(info);
	} else {
		if (init_online(info) < 0)
			return;
		play_online(info);
	}
}
