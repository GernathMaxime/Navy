/*
** EPITECH PROJECT, 2018
** socket.h
** File description:
** socket prototype
*/

#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stddef.h>

int connect_to_server(uint16_t port, const char *ip);
int accept_client(int sockfd, int backlog);
int create_server(uint16_t port);

#endif /* !SOCKET_H_ */
