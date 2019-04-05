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
#include <errno.h>
#include <string.h>
#include "my.h"
#include "env.h"

static void print_error(char *path, int stat, char *curr)
{
    if (stat == 0) {

        my_puterr(path);
        my_puterr(": Command not found.\n");
    }
    else {
        my_puterr(path);
        my_puterr(": Permission denied.\n");
    }
}

static int path_exist(char *currpath, char **bin)
{
    char *tmp = malloc(4096);
    int fd;
    DIR *dir;

    if (!tmp)
        exit(0);
    tmp = concat_path(tmp, currpath, bin[0]);
    dir = opendir(tmp);
    if (dir) {
        closedir(dir);
        return (2);
    }
    fd = open(tmp, O_RDONLY);
    if (fd == -1)
        return (0);
    else if (access(tmp, X_OK) == -1)
        return (2);
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
    if ((stat = path_exist(curr, arr)) == 1) {
        stat = exe_path(curr, arr);
        if (stat == 1) {
            free(curr);
            return;
        }
    }
    print_error(arr[0], stat, curr);
    return_value = 1;
}
