/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** cd.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "my.h"
#include "env.h"

void cd(char **arg)
{
    char *str = malloc(64);
    int stat;
    int i;
    char *tmp = malloc(4096);

    getcwd(tmp, 4096);
    for (i = 0; arg[i]; i += 1);
    if (i > 2) {
        my_puterr("cd: Too many arguments.\n");
        return;
    }
    if (!arg[1]) {
        chdir(home);
        return;
    }
    if (my_strcomp("-", arg[1])) {
        stat = chdir(last_path);
        getcwd(str, 64);
    }
    else if (my_strcomp("~", arg[1])) {
        stat = chdir(home);
        getcwd(str, 64);
    }
    else {
        getcwd(last_path, 4096);
        stat = chdir(arg[1]);
        getcwd(str, 64);
    }
    if (stat == -1) {
        if (my_strcomp(arg[1], "-")) {
            my_puterr(last_path);
            my_puterr(": No such file or directory.\n");
        } else if (my_strcomp("No such file or directory", strerror(errno))) {
                my_puterr(arg[1]);
                my_puterr(": No such file or directory.\n");
            }
        else {
            my_puterr(arg[1]);
            my_puterr(": Not a directory.\n");
        }
    }
    else
        last_path = tmp;
}
