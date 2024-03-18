/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** client
*/

#include "serv.h"

client_t *info_cli(client_t *client, client_t *list_head)
{
    client_t *before = client->before;
    client_t *after = client->after;

    if (after)
        after->before = before;
    if (before)
        before->after = after;
    free(client->cwd);
    free(client);
    if (!before)
        return after;
    else
        return list_head;
}

client_t *info_input(client_t *head, client_t *new_client)
{
    if (!new_client)
        return head;
    if (!head)
        return new_client;
    new_client->after = head;
    head->before = new_client;
    return new_client;
}

client_t *building_cli(char *cwd)
{
    client_t *new = malloc(sizeof(client_t));

    new->sock_len = sizeof(struct sockaddr_in);
    new->original_cwd = cwd;
    new->cwd = strdup(cwd);
    new->before = 0;
    new->after = 0;
    new->folder = 0;
    new->log = 0;
    new->etat = 1;
    new->passive_mode = 0;
    new->port = 0;
    return new;
}

client_t *finder(int folder, client_t *head)
{
    client_t *temp_head = head;

    while (head) {
        if (temp_head->folder == folder)
            return temp_head;
        temp_head = temp_head->after;
    }
    return 0;
}
