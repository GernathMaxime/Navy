/*
** EPITECH PROJECT, 2017
** bistro-matic
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
	int nb = 0;

	if (!str)
		return (0);
	for (int i = 0; str && str[i] != '\0'; i++, nb++);
	return (nb);
}
