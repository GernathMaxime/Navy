/*
** EPITECH PROJECT, 2018
** socket.c
** File description:
** socket
*/

#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>
#include <stdio.h>

int memsetzero(void *ptr, size_t size)
{
	char *tmp = ptr;

	if (tmp == NULL)
		return (-1);
	for (size_t i = 0; i < size; i++)
		tmp[i] = 0;
	return (0);

}

int create_server(uint16_t port)
{
	struct sockaddr_in server;
	int fd;

	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
		return (-1);
	memsetzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);
	if (bind(fd, (struct sockaddr *)&server,
		sizeof(struct sockaddr_in)) < 0) {
		close(fd);
		return (-1);
	}
	return (fd);
}

int accept_client(int sockfd, int backlog)
{
	struct sockaddr_in client;
	socklen_t clilen = sizeof(client);
	int fd;

	if (listen(sockfd, backlog) < 0)
		return (-1);
	fd = accept(sockfd, (struct sockaddr *)&client, &clilen);
	if (fd < 0)
		return (-1);
	return (fd);
}
int connect_to_server(uint16_t port, const char *ip)
{
	struct hostent *info;
	struct sockaddr_in serv_addr;
	int fd;

	info = gethostbyname(ip);
	if (info == NULL)
		return (-1);
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
		return (-1);
	memsetzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr = *(struct in_addr *)info->h_addr;
	serv_addr.sin_port = htons(port);
	if (connect(fd, (struct sockaddr *)&serv_addr,
		    sizeof(struct sockaddr)) < 0) {
		close(fd);
		return (-1);
	}
	return (fd);
}
