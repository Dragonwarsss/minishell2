/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** set_paths
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "env.h"

void set_paths(char **env)
{
    for (int i = 0; env[i]; i += 1)
        if (my_strncomp(env[i], "PATH=", 5))
            paths = my_str_to_word_array(env[i]);
}
