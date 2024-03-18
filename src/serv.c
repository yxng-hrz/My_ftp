/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** serv
*/

#include "serv.h"

int work_project(int port, char *path)
{
    int com_folder = sock_command(port);
    int nfds = 100;
    char *real_path = realpath(path, 0);

    if (real_path == NULL)
        return 1;
    if (!com_folder)
        return 1;
    choose_boucle(nfds, real_path, com_folder);
    free(real_path);
};

int replying(int client_fd, char *code, int n_lines, ...)
{
    int a = n_lines - 1;
    va_list args;
    char *msg = 0;

    va_start(args, n_lines);
    while (a >= 0) {
        msg = va_arg(args, char *);
        if (a == 0)
            dprintf(client_fd, "%s %s\r\n", code, msg);
        else
            dprintf(client_fd, "%s-%s\r\n", code, msg);
        a = a - 1;
    }
    va_end(args);
    return 0;
}
