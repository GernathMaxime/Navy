/*
** EPITECH PROJECT, 2018
** stumper1
** File description:
** str_to_tab
*/

#include "my.h"

static void fill_tab(char **res, char *str, int nb_words)
{
	int len = 0;
	int compt = 0;
	int nb = 0;

	str[0] == '"' ? len++, nb++ : 0;
	for (int i = 0; i < nb_words; i++, compt = len) {
		for (compt = len; str[len] && (nb == 1 || (str[len] != ' ' &&
		str[len] != '\t')) && str[len] != '"'; len++)
			str[len] == '"' ? nb = (nb == 0 ? 1 : 0) : 0;
		res[i] = malloc(sizeof(char) * (len - compt + 1));
		res[i][len - compt] = '\0';
		for (int j = 0; compt < len; compt++, j++)
			res[i][j] = str[compt];
		for (; str[len] && ((nb == 0 && (str[len] == ' ' ||
		str[len] == '\t')) || str[len] == '"'); len++)
			str[len] == '"' ? nb = (nb == 0 ? 1 : 0) : 0;
	}
}

static int words(char *str)
{
	int res = 1;
	int nb = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == '"' && nb == 0)
			nb = 1;
		else if (str[i] == '"' && nb == 1)
			nb = 0;
		if ((str[i] == ' ' && nb == 0) || (str[i] == '\t' && nb == 0))
			res++;
	}
	return (res);
}

char **str_to_tab(char *str)
{
	char **res = NULL;
	int nb_words = 0;

	if (!str)
		return (NULL);
	if (my_strcmp(str, "") == 0) {
		res = malloc(sizeof(char *) * 2);
		res[0] = my_strdup("");
		res[1] = NULL;
		free(str);
		return (res);
	}
	nb_words = words(str);
	res = malloc(sizeof(char *) * (nb_words + 1));
	if (!res)
		return (NULL);
	res[nb_words] = NULL;
	fill_tab(res, str, nb_words);
	free(str);
	return (res);
}
