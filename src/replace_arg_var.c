/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** replace_arg_var
*/

#include <stdlib.h>
#include "my.h"
#include "env.h"

static char ** change_if_same(char **arr, int i)
{
    char *info = malloc(4096);

    info = my_strcpynjump(arr[i], 1);
    for (int j = 0; var[j].name; j += 1) {
        if (my_strcomp(info, var[j].name))
            arr[i] = var[j].value;
    }
    for (int j = 0; envp[j]; j += 1) {
        if (my_strncomp(info, envp[j], my_strlen(info)))
            arr[i] = my_strcpynjump(envp[j], my_strlen(info) + 1);
    }
    free(info);
    return (arr);
}

void replace_arg_var(char **arr)
{
    int i;

    for (i = 0; arr[i]; i += 1) {
        if (arr[i][0] == '$') {
            arr = change_if_same(arr, i);
        }
    }
}
