/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** commands
*/

#ifndef COMMANDS_H_
    #define COMMANDS_H_

    #include "client.h"
    #include "request.h"

typedef struct cmd_s {
    char *nom;
    int (*ptr)(client_t *, request_t);
} cmd_t;

int usr_command(client_t *client, request_t request);
int psw_command(client_t *client, request_t request);
int command_noop(client_t *client, request_t request);
int command_help(client_t *client, request_t request);
int command_quit(client_t *client, request_t request);
int command_port(client_t *client, request_t request);
int command_pasv(client_t *client, request_t request);
int info_err(client_t *client, request_t request);
int mdp_command(client_t *client, request_t request);
int info_good(client_t *client, request_t request);

#endif /* !COMMANDS_H_ */
