/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strcpynjump
*/

#include <stdlib.h>
#include "my.h"

char *my_strcpynjump(char *str, int n)
{
    char *new = malloc(my_strlen(str) + 1 - n);

    for (int i = n; str[i]; i += 1)
        new[i - n] = str[i];
    new[my_strlen(str) - n] = 0;
    return (new);
}
