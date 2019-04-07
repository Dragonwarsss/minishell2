/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** builtin_env.c
*/

#include <stdlib.h>
#include "my.h"
#include "env.h"

void add_var(char *name, char *value)
{
    int i = 0;
    int j = 0;
    var_t *tmp;

    for (; var[i].name; i += 1);
    tmp = malloc(sizeof(var_t) * (i + 2));
    for (j = 0; j != i; j += 1) {
        tmp[j].name = my_strdup(var[j].name);
        tmp[j].value = my_strdup(var[j].value);
    }
    tmp[j].name = my_strdup(name);
    tmp[j].value = my_strdup(value);
    tmp[j + 1].name = NULL;
    free(var);
    var = tmp;
}

int builtin_env(char **arr)
{
    if (my_strcomp(arr[0], "env")) {
        display_env();
        return (1);
    }
    if (my_strcomp(arr[0], "setenv")) {
        if (arr[1] == NULL) {
            display_env();
            return (1);
        }
        else {
            add_var(arr[1], arr[2]);
            return (1);
        }
    }
    if (my_strcomp(arr[0], "unsetenv")) {
        return (1);
    }
    return (0);
}
