/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** serv
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <limits.h>
    #include <sys/stat.h>
    #include <libgen.h>
    #include <sys/select.h>

    #include "client.h"
    #include "request.h"
    #include "commands.h"

    #define ERR(msg) fprintf(stderr, "%s", msg)

int work_project(int port, char *path);
int choose_boucle(int nfds, char *cwd, int server_fd);
int replying(int client_fd, char *code, int n_lines, ...);
int sock_command(int port);
int counter_length(char **table);
void remove_counter(char **table);
char *my_str_to_lowcase(char *str);

#endif /* !SERVER_H_ */
