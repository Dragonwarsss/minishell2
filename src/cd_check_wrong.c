/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** check wrong things for cd builtin
*/

#include <string.h>
#include <errno.h>
#include "env.h"
#include "my.h"

void cd_check_wrong(int stat, char **arg, char *tmp)
{
    if (stat == -1) {
        if (my_strcomp(arg[1], "-")) {
            my_puterr(last_path);
            my_puterr(": No such file or directory.\n");
        } else if (my_strcomp("No such file or directory", strerror(errno))) {
            my_puterr(arg[1]);
            my_puterr(": No such file or directory.\n");
        } else {
            my_puterr(arg[1]);
            my_puterr(": Not a directory.\n");
        }
    } else
        last_path = tmp;
}
