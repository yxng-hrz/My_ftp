/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-guillaume.houriez
** File description:
** main
*/

#include "serv.h"

int handling_main(int argc, char **argv)
{
    struct stat sb;

    if (argc == 2 && !strcmp(argv[1], "-help")) {
        usage_h();
        return -1;
    }
    if (argc != 3) {
        printf("invalid args\n");
        return 1;
    }
    if (stat(argv[2], &sb) == -1 || !S_ISDIR(sb.st_mode)) {
        printf("invalid filepath\n");
        return 1;
    } else
        return 0;
}

int main(int argc, char **argv)
{
    int handling = 0;
    int work = 0;

    handling = handling_main(argc, argv);
    if (handling == -1)
        return 0;
    if (handling == 1)
        return 84;
    printf("run serv\n");
    work = work_project(atoi(argv[1]), argv[2]);
    if (work == 1)
        return 84;
    return 0;
}
