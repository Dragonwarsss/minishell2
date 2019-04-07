/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** only_semi
*/

#include "my.h"

int only_semi(char **sep)
{
    for (int i = 0; sep[i]; i += 1) {
        if (!my_strcomp(sep[i], ";")) {
            return (0);
        }
    }
    return (1);
}
