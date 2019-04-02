/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** strdup
*/

#include <stdlib.h>

char *my_strdup(char const *str)
{
    char *str_new;
    int i = 0;

    if (!str)
        return (NULL);
    for (; str[i]; i += 1);
    str_new = malloc(sizeof(char) * i + 1);
    if (!str_new)
        return (NULL);
    str_new[i] = 0;
    for (i = 0; str[i]; i += 1)
        str_new[i] = str[i];
    return (str_new);
}
