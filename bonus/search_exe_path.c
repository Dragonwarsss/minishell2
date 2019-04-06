/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** search_exe_path
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "env.h"

static char *search_bin_path(char *path, char *bin)
{
    DIR *dir = opendir(path);
    struct dirent *file;

    if (!dir)
        return (NULL);
    while ((file = readdir(dir))) {
        if (my_strcomp(file->d_name, bin)) {
            closedir(dir);
            return (path);
        }
    }
    closedir(dir);
    return (NULL);
}

char *search_exe_path(char *bin)
{
    char *stat = 0;
    char *res = malloc(4096);

    for (int i = 0; paths[i]; i += 1) {
        stat = search_bin_path(paths[i], bin);
        if (stat) {
            res = my_strcpy(res, stat);
            res = my_strcat(res, "/");
            res = my_strcat(res, bin);
            return (res);
        }
    }
    return (NULL);
}
