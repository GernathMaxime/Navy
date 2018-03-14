/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line.c
*/

#include "my.h"

char *my_realloc(char *str, int nb)
{
	int i = 0;
	char *stack = NULL;

	for (; str && str[i] != '\0'; i++);
	stack = malloc(sizeof(char) * (i + nb));
	if (!stack)
		return (NULL);
	for (int j = 0; j != i; j++)
		stack[j] = str[j];
	stack[i] = '\0';
	free(str);
	return (stack);
}

int do_read(int nb, char *buffer, int fd, char **res)
{
	ssize_t nb_read = 0;

	if (nb == 0) {
		nb_read = read(fd, buffer, READ_SIZE);
		if (nb_read == 0 && *res && *(res)[0] == '\0') {
			free(*res);
			*(res) = NULL;
			return (84);
		}
		if (nb_read == -1 || READ_SIZE <= 0 || nb_read == 0)
			return (84);
		buffer[nb_read] = '\0';
	}
	return (0);
}

char *get_next_line(const int fd)
{
	static char buffer[READ_SIZE + 1];
	static int nb = 0;
	char *res = NULL;
	int nb_res = 0;
	int i = 0;

	while (1) {
		if (do_read(nb, buffer, fd, &res) != 0)
			return (res);
		for (i = nb; buffer[i] != '\n' && buffer[i] != '\0'; i++);
		res = my_realloc(res, i - nb + 1);
		if (!res)
			return (NULL);
		for (; nb < i; nb++, nb_res++)
			res[nb_res] = buffer[nb];
		res[nb_res] = '\0';
		if (buffer[nb++] == '\n')
			return (res);
		nb = 0;
	}
}
