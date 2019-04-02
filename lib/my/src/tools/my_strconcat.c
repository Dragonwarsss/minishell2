/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strconcat
*/

#include <stdlib.h>
#include "my.h"

char *my_strconcat(char *s1, char *s2)
{
    char *str = malloc(my_strlen(s1) + my_strlen(s2) + 1);
    int i = 0;
    int j = 0;

    for (; s1[i]; i += 1)
        str[i] = s1[i];
    for (; s2[j]; j += 1)
        str[i + j] = s2[j];
    str[my_strlen(s1) + my_strlen(s2)] = 0;
    return (str);
}
