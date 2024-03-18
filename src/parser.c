/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** parser
*/

#include "serv.h"

char **space_create(char *str, char *sep)
{
    char *save_pointer = 0;
    char **output = 0;
    char *token = 0;
    int size = 0;
    int index = 0;

    for (int a = 0; str[a]; a = a + 1)
        if (!strncmp(&str[a], sep, strlen(sep)))
            size++;
    output = calloc(size + 2, sizeof(char *));
    output[0] = 0;
    token = strtok_r(str, sep, &save_pointer);
    while (token) {
        output[index] = strdup(token);
        output[index + 1] = 0;
        index++;
        token = strtok_r(0, sep, &save_pointer);
    }
    return output;
}

request_t lire_requete(char *raw)
{
    request_t output;
    char **split_msg = 0;
    char *msg = 0;

    msg = strtok(raw, "\r\n");
    if (!msg) {
        output.yessir = 0;
        return output;
    }
    split_msg = space_create(msg, " ");
    if (counter_length(split_msg) < 1) {
        output.yessir = 0;
        return output;
    }
    output.yessir = 1;
    output.avant = strdup(my_str_to_lowcase(split_msg[0]));
    output.argument = counter_length(split_msg) < 2 ?
    strdup("") : strdup(split_msg[1]);
    remove_counter(split_msg);
    return output;
}
