/*
** EPITECH PROJECT, 2018
** my_calloc.c
** File description:
** my_calloc
*/

#include <stdlib.h>

void *my_calloc(size_t nmemb, size_t size)
{
	char *ptr;
	unsigned int i = 0;

	ptr = malloc(size * nmemb);
	if (!(ptr))
		return (NULL);
	while (i < size * nmemb) {
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
