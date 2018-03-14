/*
** EPITECH PROJECT, 2018
** navy.h
** File description:
** navy proto struct
*/

#ifndef _NAVY_H_
#define _NAVY_H_

#include <sys/types.h>
#include <signal.h>

int bit;

#define WAIT "waiting for enemy's attack...\n"

typedef struct coord_s coord_t;
typedef struct info_s info_t;

struct coord_s {
	int x;
	int y;
};

struct info_s {
	int my_pid;
	int en_pid;
	char **my_map;
	char **en_map;
	int hit;
};

int fill_board(info_t *, int, char **);
char **check_start(int, char **);
char **create_map(char **);
char **empty_map(void);
void print_map(char **);
int add_ship(char **, coord_t *, char);
coord_t *get_coord(char *);
int receive(int);
void send(int, int);
void handle_pid(int, siginfo_t *, void *);
void handle(int, siginfo_t *, void *);
void recup_pid(int, char **, info_t *);
int game(int, info_t *);
void print_game(info_t *);
int is_ended(info_t *);
int is_coord(char *);
int is_good_line(char *);
char **get_pos(char *);

#endif /* !NAVY_H_ */
