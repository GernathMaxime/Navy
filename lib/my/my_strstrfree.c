/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_strstrfree
*/

#include "my.h"

void my_strstrfree(char **str)
{
	for (int i = 0; str && str[i]; i++)
		if (str[i])
			free(str[i]);
	if (str)
		free(str);
	str = NULL;
}
