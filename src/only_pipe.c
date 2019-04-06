/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** only_pipe
*/

#include "my.h"
#include "env.h"

static int is_pipe(char *str)
{
    if (my_strcomp(str, "|"))
        return (1);
    return (0);
}

int only_pipe(char *str)
{
    char **args = my_str_to_word_array(str);
    char **sep = keep_correct_sep(args);
    int count_pipe = 0;

    for (int i = 0; sep[i]; i += 1) {
        if (is_pipe(sep[i]))
            count_pipe += 1;
        if (is_sep(sep[i]) && !is_pipe(sep[i])) {
            return (0);
        }
    }
    if (count_pipe == 0)
        return (0);
    return (1);
}
