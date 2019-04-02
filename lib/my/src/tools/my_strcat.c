/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = 0;

    if (!src)
        return (dest);
    len = my_strlen(dest);
    while (src[i]) {
        dest[len + i] = src[i];
        i += 1;
    }
    dest[len + i] = 0;
    return (dest);
}
