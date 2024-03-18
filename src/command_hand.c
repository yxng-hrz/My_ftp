/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** command_hand
*/

#include "serv.h"

client_t *control_links(int server_folder, client_t *client_list, char *cwd)
{
    client_t *new_client = building_cli(cwd);

    new_client->folder = accept(server_folder,
    (struct sockaddr *)&new_client->client_sock, &new_client->sock_len);
    if (new_client->folder == -1) {
        ERR("Accepting incoming connection has failed\n");
        return client_list;
    } else {
        client_list = info_input(client_list, new_client);
        replying(new_client->folder, "220", 1, "Service ready for new user");
    }
    return client_list;
}

int run_call(client_t *client, request_t request)
{
    int a = 0;
    cmd_t commands[] = {
        { "user", &usr_command }, { "pass", &psw_command },
        { "noop", &command_noop },
        { "help", &command_help },
        { "cwd", &info_err },
        { "pwd", &mdp_command },
        { "quit", &command_quit },
        { "port", &command_port },
        { "cdup", &info_good },
        { "pasv", &command_pasv },
        { "0", 0 }
    };

    while (commands[a].ptr != 0) {
        if (!strcmp(request.avant, commands[a].nom))
            return commands[a].ptr(client, request);
        a = a + 1;
    }
    return -1;
}

client_t *control_call(client_t *client_list, client_t *head, char *aloc)
{
    request_t request = lire_requete(aloc);
    int comandd = run_call(head, request);

    if (request.yessir) {
        if (comandd < 0)
            replying(head->folder, "500", 1,
            "Synthaxe Error, command unrecognized.");
        if (comandd == 1) {
            close(head->folder);
            client_list = info_cli(head, client_list);
        }
    } else
        replying(head->folder, "500", 1,
        "Synthaxe Error, command unrecognized.");
    free(request.argument);
    free(request.avant);
    return client_list;
}

client_t *handle_client_data(client_t *current,
    char *aloc, client_t *client_list)
{
    int a = read(current->folder, aloc, 4096);

    if (!a) {
        return info_cli(current, client_list);
    }
    return control_call(client_list, current, aloc);
}

client_t *control_cli(client_t *client_list, fd_set *readfds, int nfds)
{
    char *aloc = calloc(4096, sizeof(char));
    client_t *head = client_list;
    request_t request;

    for (client_t *current = head; current != NULL; current = current->after) {
        if (FD_ISSET(current->folder, readfds)) {
            client_list = handle_client_data(current, aloc, client_list);
        }
    }
    free(aloc);
    return client_list;
}
