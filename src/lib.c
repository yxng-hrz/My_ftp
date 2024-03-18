/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** lib
*/

#include "serv.h"

int sock_command(int port)
{
    int com_folder = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    socklen_t sock_len = sizeof(server_addr);
    int opt = 1;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = ntohs(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    setsockopt(com_folder, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (bind(com_folder, (struct sockaddr *)&server_addr, sock_len) < 0) {
        ERR("Server command socket binding failed\n");
        return 0;
    }
    if (listen(com_folder, 10) == -1) {
        ERR("Server command socket listening failed\n");
        return 0;
    }
    return com_folder;
}

char *my_str_to_lowcase(char *str)
{
    int a = 0;

    while (str[a] != '\0') {
        str[a] = tolower(str[a]);
        a = a + 1;
    }
    return str;
}

int counter_length(char **table)
{
    int a = 0;

    while (table[a] != 0) {
        a = a + 1;
    }
    return a;
}

void remove_counter(char **table)
{
    int a = 0;

    while (table[a] != 0) {
        free(table[a]);
        a = a + 1;
    }
    free(table);
}

void usage_h(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport is the port number on which the server socket listens\n");
    printf("\tpath is the path to the home ");
    printf("directory for the Anonymour user\n");
}
