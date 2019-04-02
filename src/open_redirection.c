/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** open_redirection.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char *file_redirect(char **bin)
{
    int i;

    for (i = 0; bin[i]; i += 1) {
        if (my_strcomp(bin[i], ">"))
            return (bin[i + 1]);
        if (my_strcomp(bin[i], ">>"))
            return (bin[i + 1]);
    }
    return (bin[i]);
}

int open_redirection(int redirection, char *file)
{
    int fd;

    if (redirection == 1)
        fd = open(file, O_RDWR | O_CREAT | O_APPEND | O_TRUNC,
        S_IRUSR | S_IWUSR);
    else if (redirection == 2)
        fd = open(file, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    return (fd);
}
