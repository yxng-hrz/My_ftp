/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** command
*/

#include "serv.h"

int command_quit(client_t *client, request_t request)
{
    replying(client->folder, "221", 1, "Service closing control connection");
    return 1;
}

int command_noop(client_t *client, request_t request)
{
    return replying(client->folder, "200", 1, "Command okay.");
}

int command_help(client_t *client, request_t request)
{
    return replying(client->folder, "214", 1, "This is the usage");
}

int command_port(client_t *client, request_t request)
{
    client->port = atol(request.argument);
    if (!client->log)
        return replying(client->folder, "530", 1, "Not logged in.");
    if (request.argument[0] == '\0' || client->port <= 0)
        return replying(client->folder, "501", 1,
        "Synthaxe error in params or args");
    return replying(client->folder, "200", 1, "Command Ok.");
}

int command_pasv(client_t *client, request_t request)
{
    int a = 1;
    int b = 50;
    int c = 47;
    int d = 127;
    int e = 0;
    int f = 0;

    if (!client->log)
        return replying(client->folder, "530", 1, "Not logged in.");
    client->passive_mode = 1;
    dprintf(client->folder, "227 Entering Passive Mode %d,%d,%d,%d,%d,%d\r\n",
            d, e, f, a, b, c);
    return 0;
}
