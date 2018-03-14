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
#include <ncurses.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stddef.h>

int bit;

#define WAIT "waiting for enemy's attack...\n"

typedef struct coord_s coord_t;
typedef struct info_s info_t;
typedef struct music_s music_t;

struct coord_s {
	int x;
	int y;
};

struct music_s {
	sfMusic *touched;
	sfMusic *missed;
};

struct info_s {
	int joiner;
	int fd;
	int difficulty;
	int online;
	char **my_map;
	char **en_map;
	char **bot_map;
	char **empty_map;
	music_t *music;
};

int is_good_line(char *);
int is_good_pos(char *);
info_t *create_info(char *);
void destroy_info(info_t *);
char **empty_map(void);
coord_t *get_coord(char *);
int add_ship(char **, coord_t *, char);
int fill_map(char **, char **);
char **bot_map_create(void);
char **get_map(info_t *, int, int);
char **create_map(char *);
int bot2(char **);
int bot3(char **, char **);
void play_online(info_t *);
int bot4(char **, char **);
int take_random(char **);
int diago(char **);
int focus_boat(char **);
int take_smaller(char **);
int take_random_point(char **);
int init_online(info_t *);
int smart_move(char **, int, int);
int next_smart(char **, int, int);
int chose_shot(info_t *, int *);
void ncurses_mode(info_t *);
void apply_map(char **, char **, int, music_t *);
void get_getched(int, int *, int *, int);
void play_game(info_t *);
void get_escape(int, int *);
void draw_maps(char **, char **);
void draw_map(char **, int);
int human(info_t *, int *);
void ended_screen(int, info_t *);
int is_ended(info_t *);
void ended_scree(int, info_t *, int);
int is_ende(info_t *);
char *getip(void);
void enter_word(char *, char *, int *);
void getch_me(char *, int *, int, int *);
int connect_to_server(uint16_t, char *);
int accept_client(int, int);
int create_server(uint16_t);

#endif /* !NAVY_H_ */
