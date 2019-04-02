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

void cd(char *arg)
{
    char *str = malloc(64);
    int stat;

    if (!arg) {
        chdir(home);
        return;
    }
    if (my_strcomp("-", arg)) {
        stat = chdir(home);
        getcwd(str, 64);
    }
    else if (my_strcomp("~", arg)) {
        stat = chdir(home);
        getcwd(str, 64);
    }
    else {
        stat = chdir(arg);
        getcwd(str, 64);
    }
    if (stat == -1)
        my_printf("%s\n", strerror(errno));
}
