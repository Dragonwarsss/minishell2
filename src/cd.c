/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** cd.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "my.h"
#include "env.h"

int cd_basic(char **arg)
{
    char *tmp = malloc(4096);
    int i = 0;

    if (!tmp)
        exit(84);
    getcwd(tmp, 4096);
    for (; arg[i]; i += 1);
    if (i > 2) {
        my_puterr("cd: Too many arguments.\n");
        return (1);
    }
    if (!arg[1]) {
        last_path = tmp;
        chdir(home);
        return (1);
    }
    return (0);
}

void cd(char **arg)
{
    char *str = malloc(64);
    int stat;
    char *tmp = malloc(4096);

    getcwd(tmp, 4096);
    if (cd_basic(arg))
        return;
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
    cd_check_wrong(stat, arg, tmp);
}
