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
    int is_first = 0;

    if (!tmp)
        exit(84);
    for (int i = 1; args[i]; i += 1) {
        if (is_sep(args[i])) {
            if (is_first == 0) {
                tmp = my_strcpy(tmp, args[i]);
                tmp = my_strcat(tmp, " ");
                is_first += 1;
            } else {
                tmp = my_strcat(tmp, args[i]);
                tmp = my_strcat(tmp, " ");
            }
        }
    }
    return (my_str_to_word_array(tmp));
}
