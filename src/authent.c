/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** authent
*/

#include "serv.h"

int psw_command(client_t *client, request_t request)
{
    if (client->log)
        return replying(client->folder, "230", 1, "User logged in, proceed");
    if (client->etat != 2)
        return replying(client->folder, "503", 1, "Bad sequence of commands");
    else if (!strcmp(request.argument, "")) {
        client->log = 1;
        client->etat = 0;
        return replying(client->folder, "230", 1, "User logged in, proceed");
    } else {
        client->etat = 1;
        return replying(client->folder, "530", 1, "Not logged in.");
    }
}

int usr_command(client_t *client, request_t request)
{
    if (client->log)
        return replying(client->folder, "230", 1, "User logged in, proceed");
    if (!strcmp(request.argument, "Anonymous")) {
        client->etat = 2;
        return replying(client->folder, "331", 1,
        "User name okay, need password.");
    }
    if (client->etat == 2) {
        client->etat = 1;
        return replying(client->folder, "503", 1, "Bad sequence of commands");
    }
    return replying(client->folder, "530", 1, "Not logged in");
}
