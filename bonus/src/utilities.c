/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** utilities.c
*/

#include "my.h"
#include "navy.h"

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

int is_good_pos(char *file)
{
	int fd = open(file, O_RDONLY);
	char **pos = malloc(sizeof(char *) * 5);
	int i = 0;

	for (; pos && i < 5 && (pos[i] = get_next_line(fd)); i++);
	if (i != 4 || pos[4])
		return (84);
	for (i = 0; i < 4; i++)
		if (is_good_line(pos[i]) != 0)
			return (84);
	if (pos[0][0] + pos[1][0] + pos[2][0] + pos[3][0] != 206)
		return (84);
	close(fd);
	return (0);
}

info_t *create_info(char *file)
{
	info_t *info = malloc(sizeof(*info));
	music_t *music = malloc(sizeof(*music));

	if (!info || !music)
		return (NULL);
	info->online = 0;
	info->difficulty = 0;
	if (my_strcmp("random", file) != 0)
		info->my_map = create_map(file);
	else
		info->my_map = bot_map_create();
	info->en_map = empty_map();
	info->bot_map = NULL;
	info->music = music;
	info->music->touched = sfMusic_createFromFile("usage/touched.ogg");
	info->music->missed = sfMusic_createFromFile("usage/missed.ogg");
	return (info);
}

void destroy_info(info_t *info)
{
	my_strstrfree(info->my_map);
	my_strstrfree(info->en_map);
	my_strstrfree(info->bot_map);
	sfMusic_destroy(info->music->touched);
	sfMusic_destroy(info->music->missed);
	free(info->music);
	free(info);
}
