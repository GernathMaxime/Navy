/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define READ_SIZE 10
#define MAX 2147483647
#define MIN -2147483648
#define NB_FLAGS 3

typedef struct function_s function_t;

struct function_s {
	char flag;
	void (*functions)(va_list ap, int output);
};

int my_strlen(char *);
int my_strcmp(char *, char *);
int my_strncmp(char *, char *, int);
int is_alphanum(char *);
long my_getnbr(char *);
char *my_revstr(char *);
char *my_strdup(char *);
char **my_strstrdup(char **);
void my_strstrfree(char **);
char *my_itoa(int);
int my_atoi(char *);
char *my_strcat(char*, char*);
char *my_chardup(char);
int my_strcmp(char *, char *);
void my_printf_str(va_list, int);
void my_printf_char(va_list, int);
void my_printf_nbr(va_list, int);
void my_putstr(char *, int);
void my_putchar(char, int);
char *my_ftoa(float);
int my_printf(char *, int, ...);
int my_putnbr(long, int);
char *clean(char *);
char *get_next_line(int);
char **str_to_tab(char *);
int nb_occ(char *, char);
int is_int_in(char *, int, int);
void *my_calloc(size_t nmemb, size_t size);
int convert_bin(char *, int);
int my_str_isnum(char *str);

#endif //MY_H
