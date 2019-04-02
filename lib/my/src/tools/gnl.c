/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

#define BUFF_SIZE 1

char *my_realloc(char *str)
{
    char *str2;
    int i = 0;

    str2 = malloc(sizeof(char) * my_strlen(str) + 2);
    while (str[i]) {
        str2[i] = str[i];
        i += 1;
    }
    str2[i + 1] = '\0';
    free(str);
    return (str2);
}

char *gnl(int fd)
{
    static char buffer[BUFF_SIZE];
    int i = 0;
    int size = 0;
    char *str = malloc(sizeof(char));

    str[0] = '\0';
    while ((size = read(fd, buffer, BUFF_SIZE)) > 0 && buffer[0] != '\n') {
        str = my_realloc(str);
        str[i] = buffer[0];
        i += 1;
    }
    if (size == 0 && i == 0)
        return (NULL);
    return (str);
}
