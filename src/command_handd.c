/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** command_handd
*/

#include "serv.h"

int choose_boucle(int nfds, char *cwd, int server_fd)
{
    fd_set readfds[100];
    client_t *client_list = 0;
    client_t *head = 0;

    for (;;) {
        head = client_list;
        FD_ZERO(readfds);
        FD_SET(server_fd, readfds);
        for (client_t *current = head;
            current != 0; current = current->after) {
            FD_SET(current->folder, readfds);
        }
        if (select(nfds, readfds, 0, 0, 0)) {
            client_list = control_cli(client_list, readfds, nfds);
            if (FD_ISSET(server_fd, readfds)) {
                client_list = control_links(server_fd, client_list, cwd);
            }
        }
    }
    return 0;
}
