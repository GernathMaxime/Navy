/*
** EPITECH PROJECT, 2018
** check_start.c
** File description:
** check_start
*/

#include "my.h"

int is_good_line(char *line)
{
	if (my_strlen(line) != 7 || line[1] != ':' || line[4] != ':')
		return (84);
	if (line[0] > '5' || line[0] < '2')
		return (84);
	if (line[3] > '8' || line[3] < '1' || line[6] > '8' || line[6] < '1')
		return (84);
	if (line[2] > 'H' || line[2] < 'A' || line[5] > 'H' || line[5] < 'A')
		return (84);
	if (line[2] == line[5] && line[6] - line[3] + '1' == line[0])
		return (0);
	else if (line[3] == line[6] && line[5] - line[2] + '1' == line[0])
		return (0);
	else
		return (84);
}

char **get_pos(char *str)
{
	int fd = open(str, O_RDONLY);
	char **pos = malloc(sizeof(char *) * 5);
	int i = 0;

	if (fd < 0 || !pos)
		return (NULL);
	for (; i < 5 && (pos[i] = get_next_line(fd)); i++);
	if (i != 4 || pos[4])
		return (NULL);
	for (i = 0; i < 4; i++)
		if (is_good_line(pos[i]) != 0)
			return (NULL);
	if (pos[0][0] + pos[1][0] + pos[2][0] + pos[3][0] != 206)
		return (NULL);
	close(fd);
	return (pos);
}

char **check_start(int ac, char **av)
{
	if (ac < 2 || ac > 3)
		return (NULL);
	if (ac == 3 && is_int_in(av[1], 1, MAX) != 0)
		return (NULL);
	return (get_pos(av[ac - 1]));
}
