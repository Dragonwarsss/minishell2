/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** sort_tab
*/

#include <stdlib.h>
#include "my.h"

char *my_putlow(char *str)
{
    char *nstr = malloc(sizeof(char) * my_strlen(str) + 1);

    for (int i = 0; i != my_strlen(str); i += 1) {
        nstr[i] = str[i];
        if (nstr[i] >= 'A' && nstr[i] <= 'Z')
            nstr[i] += 32;
    }
    return (nstr);
}

int compare_words(char *str1, char *str2)
{
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    int min;

    str1 = my_putlow(str1);
    str2 = my_putlow(str2);
    if (size1 < size2)
        min = size1;
    else
        min = size2;
    if (my_strncomp(str1, str2, min) && size1 > size2)
        return (2);
    for (int i = 0; i != min; i += 1)
        if (str1[i] < str2[i])
            return (1);
        else if (str1[i] > str2[i])
            return (2);
    return (0);
}

int is_sorted(char **tab, int size)
{
    int stat;

    for (int i = 0; i != size - 1; i += 1) {
        stat = compare_words(tab[i], tab[i + 1]);
        if (stat == 2)
            return (0);
    }
    return (1);
}
