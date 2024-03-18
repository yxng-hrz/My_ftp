/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** request
*/

#ifndef REQUEST_H_
    #define REQUEST_H_

typedef struct request_s {
    int yessir;
    char *avant;
    char *argument;
} request_t;

request_t lire_requete(char *raw);

#endif /* !REQUEST_H_ */
