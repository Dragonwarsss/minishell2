/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** exe_path
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
#include "my.h"
#include "env.h"

char **keepnarg(char **arg)
{
    int i = 0;
    char **new;

    for (; arg[i]; i += 1) {
        if (my_strcomp(arg[i], ">"))
            break;
        if (my_strcomp(arg[i], ">>"))
            break;
    }
    new = malloc(sizeof(char*) * (i + 1));
    new[i] = NULL;
    for (int j = 0; j != i; j += 1)
        new[j] = my_strdup(arg[j]);
    return (new);
}

int search_redirection(char **arg)
{
    int i = 0;

    for (; arg[i]; i += 1) {
        if (my_strcomp(arg[i], ">"))
            return (1);
        if (my_strcomp(arg[i], ">>"))
            return (2);
    }
    return (0);
}

char *concat_path(char *info_path, char *path, char *bin)
{
    info_path = my_strcpy(info_path, path);
    if (info_path[my_strlen(info_path)] != '/')
        info_path = my_strcat(info_path, "/");
    info_path = my_strcat(info_path, bin);
    return (info_path);
}

int exe_path(char *path, char **bin)
{
    pid_t pid = fork();
    char *info_path = malloc(PATH_MAX);
    int stat;
    int redirection = 0;
    char **args;
    int fd;

/*    if (is_pipe(bin)) {
        do_pipe(path, bin);
        return (1);
        }*/
    redirection = search_redirection(bin);
    if (redirection)
        args = keepnarg(bin);
    info_path = concat_path(info_path, path, bin[0]);
    if (pid == 0) {
        if (redirection) {
            fd = open_redirection(redirection, file_redirect(bin));
            dup2(fd, 1);
            dup2(fd, 2);
            close(fd);
            stat = execve(info_path, args, envp);
            if (stat == -1)
                return (0);
        }
        else {
            stat = execve(info_path, bin, envp);
            if (stat == -1)
                return (0);
        }
    } else {
        waitpid(pid, &stat, WUNTRACED);
        if (stat == 139)
            my_printf("Segmentation fault (core dumped)\n");
        return_value = stat;
    }
    return (1);
}
