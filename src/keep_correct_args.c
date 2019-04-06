/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "env.h"

static int search_sep_index(char **args, int i)
{
    int j = 0;

    if (i == 0)
        return (0);
    for (int k = 0; args[k]; k += 1) {
        if (is_sep(args[k]))
            j += 1;
        if (j == i)
            return (k + 1);
    }
    return (0);
}

char **keep_correct_args(char **args, int i)
{
    char *tmp = malloc(4096);
    int index = search_sep_index(args, i);

    if (!tmp)
        exit(84);
    for (int j = index; is_sep(args[j]) == 0 && args[j]; j += 1) {
        tmp = my_strcat(tmp, args[j]);
        tmp = my_strcat(tmp, " ");
        if (!args[j + 1])
            break;
    }
    return (my_str_to_word_array(tmp));
}
