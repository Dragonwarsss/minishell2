/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** display_prompt
*/

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "my.h"
#include "env.h"

void copy_home(char **env)
{
    int i;
    char *str;

    for (i = 0; env[i]; i += 1)
        if (my_strncomp("HOME=", env[i], 5))
            str = my_strdup(env[i]);
    home = my_strcpynjump(str, 5);
}

void display_prompt(void)
{
    char *str = malloc(PATH_MAX);

    getcwd(str, PATH_MAX);
    if (my_strncomp(home, str, my_strlen(home)))
        str = my_strcpynjump(str, my_strlen(home));
    my_printf("[%s ~%s]$ ", user, str);
}
