/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>

typedef struct client_s {
    int folder;
    int log;
    struct sockaddr_in client_sock;
    socklen_t sock_len;
    int etat;
    char *original_cwd;
    char *cwd;
    struct client_s *after;
    struct client_s *before;
    int port;
    int passive_mode;
} client_t;

client_t *info_input(client_t *head, client_t *new_client);
client_t *info_cli(client_t *client, client_t *list_head);
client_t *finder(int fd, client_t *head);
client_t *building_cli(char *cwd);

#endif /* !CLIENT_H_ */
