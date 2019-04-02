/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** find_exec.c
*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"

void find_exec(char **arr)
{
    DIR *dir = opendir("/bin");
    struct dirent *file = NULL;

    while ((file = readdir(dir)) != NULL) {
        if (my_strcomp(file->d_name, bin)) {
            exe_path("/bin", bin);
            return;
        }
    }
    my_printf("%s: Command not found.\n", bin);
}
