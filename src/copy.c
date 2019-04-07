/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** main.c
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "env.h"

void random_func(__attribute__((unused))int sig)
{
    my_printf("\n");
    display_prompt();
    return;
}

void copy_user(char **env)
{
    int i;
    char *str;

    if (!env[0]) {
        user = ">";
        return;
    }
    for (i = 0; env[i]; i += 1)
        if (my_strncomp("USER=", env[i], 5))
            str = my_strdup(env[i]);
    user = my_strcpynjump(str, 5);
}

void copy_env(char **env)
{
    int i = 0;
    int c = 0;

    if (!env[0]) {
        envp = NULL;
        return;
    }
    for (i = 0; env[i]; c += 1, i += 1);
    envp = malloc(sizeof(char*) * (c + 1));
    envp[c] = NULL;
    for (i = 0; env[i]; i += 1)
        envp[i] = my_strdup(env[i]);
}
