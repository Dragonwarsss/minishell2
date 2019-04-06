/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** trypath
*/

#include <unistd.h>
#include "env.h"

void trypath(char **arr, int stat)
{
    if (access(arr[0], X_OK) == 0) {
        try_exe(arr[0], arr);
        return;
    }
    print_error(arr[0], stat);
    return_value = 1;
}
