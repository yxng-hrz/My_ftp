/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** command_ret
*/

#include "serv.h"

int info_error(char *pass, client_t *client)
{
    struct stat sb;

    if (stat(pass, &sb) < 0) {
        free(pass);
        return replying(client->folder, "550", 1,
        "File action not taken. (File not found)");
    } else if (!S_ISDIR(sb.st_mode)) {
        free(pass);
        return replying(client->folder, "550", 1,
        "File action not taken. (File not found)");
    }
    return 1;
}

int info_err(client_t *client, request_t request)
{
    struct stat sb;
    char *pass = 0;

    if (!client->log)
        return replying(client->folder, "530", 1, "Not logged in.");
    if (request.argument[0] == '\0')
        return replying(client->folder, "501", 1,
        "Synthaxe error in params or args");
    chdir(client->cwd);
    pass = realpath(request.argument, 0);
    if (!info_error(pass, client))
        return 0;
    free(client->cwd);
    client->cwd = pass;
    return replying(client->folder, "250", 1,
    "Requested file action okay, completed");
}

int mdp_command(client_t *client, request_t request)
{
    if (!client->log)
        return replying(client->folder, "530", 1, "Not logged in.");
    return replying(client->folder, "257", 1, client->cwd);
}

int info_good(client_t *client, request_t request)
{
    char *pass = 0;

    if (!client->log)
        return replying(client->folder, "530", 1, "Not logged in.");
    pass = realpath(dirname(client->cwd), 0);
    free(client->cwd);
    client->cwd = pass;
    return replying(client->folder, "200", 1, "Command Ok..");
}
