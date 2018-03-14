/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_ftoa
*/

#include "my.h"

char *my_ftoa(float nb)
{
	int integer = (int)nb;
	char *res = NULL;

	res = my_strcat(my_itoa(integer), my_chardup('.'));
	nb -= integer;
	nb = nb * 100;
	res = my_strcat(res, my_itoa(nb));
	return (res);
}
