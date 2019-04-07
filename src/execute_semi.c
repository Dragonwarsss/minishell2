/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** execute_semi
*/

#include "my.h"
#include "env.h"

void execute_semi(char ***args)
{
    int stat;
    char *bin;

    while (*args != NULL) {
        bin = search_exe_path(*args[0]);
        try_exe(bin, *args);
        args++;
    }
    return;
}
