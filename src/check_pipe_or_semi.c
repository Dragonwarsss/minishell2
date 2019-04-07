/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** check if there is semi or pipe
*/

#include <stdlib.h>
#include "my.h"
#include "env.h"

static void free_tmp(char *str, char **tab)
{
    free(str);
    for (int i = 0; tab[i]; i += 1)
        free(tab[i]);
    free(tab);
}

static char ***get_args(char *str)
{
    char ***mult;
    char **tab;
    char *copy = my_strdup(str);
    int many_sep = 0;

    tab = my_str_to_word_array(copy);
    for (int i = 0; copy[i]; i += 1)
        if (copy[i] == ';' || copy[i] == '|')
            many_sep += 1;
    mult = malloc(sizeof(char**) * (many_sep + 2));
    mult[many_sep + 1] = NULL;
    for (int i = 0; i != many_sep + 1; i += 1) {
        mult[i] = my_str_to_word_array(copy);
        mult[i] = keep_correct_args(mult[i], i);
    }
    free_tmp(copy, tab);
    return (mult);
}

int check_pipe_or_semi(char *str)
{
    char **sep = keep_correct_sep(my_str_to_word_array(str));
    char ***args;

    if (!sep[0]) {
        return (0);
    }
    if (only_semi(sep)) {
        args = get_args(str);
        execute_semi(args);
        return (1);
    }
    else if (only_pipe(sep)) {
        args = get_args(str);
        execute_pipe(args);
        return (1);
    }
    return (0);
}
