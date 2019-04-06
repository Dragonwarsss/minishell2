/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** execute pipe
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "env.h"

int execute_pipe(char *str)
{
    char ***mult_args;
    char **tab;
    char *copy = my_strdup(str);
    int many_sep = 0;

    tab = my_str_to_word_array(copy);
    for (int i = 0; copy[i]; i += 1)
        if (copy[i] == '|')
            many_sep += 1;
    mult_args = malloc(sizeof(char**) * (many_sep + 2));
    mult_args[many_sep + 1] = NULL;
    for (int i = 0; i != many_sep + 1; i += 1) {
        mult_args[i] = my_str_to_word_array(copy);
        mult_args[i] = keep_correct_args(mult_args[i], i);
    }
    exe_path_pipe(mult_args);
}
