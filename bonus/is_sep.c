/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** is_sep
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int is_sep(char *str)
{
    if (my_strcomp(str, ">") || my_strcomp(str, "|") ||
        my_strcomp(str, ">>") || my_strcomp(str, ";"))
        return (1);
    return (0);
}
