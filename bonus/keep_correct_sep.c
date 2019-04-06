/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** keep sep
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "env.h"

char **keep_correct_sep(char **args)
{
    char *tmp = malloc(4096);

    if (!tmp)
        exit(84);
    for (int i = 0; args[i]; i += 1) {
        if (is_sep(args[i])) {
            tmp = my_strcat(tmp, args[i]);
            tmp = my_strcat(tmp, " ");
        }
    }
    return (my_str_to_word_array(tmp));
}
