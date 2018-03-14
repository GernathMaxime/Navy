/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** main.c
*/

#include "my.h"
#include "navy.h"

void print_usage(void)
{
	my_putstr("\nUSAGE :\n", 1);
	my_putstr("\t./navy \"random / filename\".\n", 1);
	my_putstr("\n", 1);
	my_putstr("ARGUMENTS :\n", 1);
	my_putstr("\trandom : generate a random map.\n", 1);
	my_putstr("\tfilename : PATH to a file following this exemple :\n", 1);
	my_putstr("\t\t2:C1:C2\n", 1);
	my_putstr("\t\t3:D1:D3\n", 1);
	my_putstr("\t\t4:E1:E4\n", 1);
	my_putstr("\t\t5:F1:F5\n\n", 1);
}

int handle_errors(int ac, char **av)
{
	if (ac != 2)
		return (84);
	if (my_strcmp("random", av[1]) != 0 && is_good_pos(av[1]) != 0)
		return (84);
	return (0);
}

int main(int ac, char **av)
{
	info_t *info = NULL;

	if (handle_errors(ac, av) != 0) {
		print_usage();
		return (84);
	}
	srand(time(NULL) * getpid());
	info = create_info(av[1]);
	ncurses_mode(info);
	endwin();
	destroy_info(info);
	return (0);
}
