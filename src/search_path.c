/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** search_path.c
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>
#include "my.h"
#include "env.h"

int search_bin(char *path, char **bin)
{
    DIR *dir = opendir(path);
    struct dirent *file;

    if (!dir)
        return (0);
    while ((file = readdir(dir))) {
        if (my_strcomp(file->d_name, bin[0])) {
            exe_path(path, bin);
            closedir(dir);
            return (1);
        }
    }
    closedir(dir);
    return (0);
}

void search_path(char **arr)
{
    int stat = 0;
    char *curr = malloc(PATH_MAX);

    replace_arg_var(arr);
    for (int i = 0; paths[i]; i += 1) {
        stat = search_bin(paths[i], arr);
        if (stat) {
            free(curr);
            return;
        }
    }
    getcwd(curr, PATH_MAX);
    stat = exe_path(curr, arr);
    if (stat == 1) {
        free(curr);
        return;
    }
    my_printf("%s: command not found.\n", arr[0]);
    return_value = 1;
}
