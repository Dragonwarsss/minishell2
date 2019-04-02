/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** sort_tab
*/

#include <stdlib.h>
#include "my.h"

int compare_words_reverse(char *str1, char *str2)
{
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    int min;

    str1 = my_putlow(str1);
    str2 = my_putlow(str2);
    if (size1 > size2)
        min = size1;
    else
        min = size2;
    for (int i = 0; i != min; i += 1)
        if (str1[i] > str2[i])
            return (1);
        else if (str1[i] < str2[i])
            return (2);
    return (0);
}

int is_sorted_reverse(char **tab, int size)
{
    int stat;

    for (int i = 0; i != size - 1; i += 1) {
        stat = compare_words_reverse(tab[i], tab[i + 1]);
        if (stat == 2)
            return (0);
    }
    return (1);
}
