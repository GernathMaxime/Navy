/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** human.c
*/

#include "my.h"
#include "navy.h"

int human(info_t *info, int *j)
{
	static int choice = 0;
	int nb = getch();

	nb == KEY_DOWN && choice < 70 ? choice += 10 : 0;
	nb == KEY_UP && choice > 9 ? choice -= 10 : 0;
	nb == KEY_LEFT && choice % 10 > 0 ? choice -= 1 : 0;
	nb == KEY_RIGHT && choice % 10 < 7 ? choice += 1 : 0;
	nb == 27 ? (*j) = -5 : 0;
	if (nb == 10) {
		apply_map(info->bot_map, info->en_map, choice, info->music);
		apply_map(info->bot_map, info->bot_map, choice, info->music);
		return (choice);
	}
	(*j)--;
	return (choice);
}
