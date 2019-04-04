/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** search_path.c
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>
#include "my.h"
#include "env.h"

static int path_exist(char *currpath, char **bin)
{
    char *tmp = malloc(4096);
    int fd;

    if (!tmp)
        exit(0);
    tmp = my_strcpy(tmp, currpath);
    if (tmp[my_strlen(tmp) - 1] != '/')
        tmp = my_strcat(tmp, "/");
    tmp = my_strcat(tmp, bin[0]);
    fd = open(tmp, O_RDONLY);
    if (fd == -1)
        return (0);
    close(fd);
    return (1);
}

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
    if (path_exist(curr, arr)) {
        stat = exe_path(curr, arr);
        if (stat == 1) {
            free(curr);
            return;
        }
    }
    my_puterr(arr[0]);
    my_puterr(": Command not found.\n");
    return_value = 1;
}
