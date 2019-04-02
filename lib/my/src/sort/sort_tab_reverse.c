/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** sort_tab
*/

#include <stdlib.h>
#include "my.h"

char **manage_tab_reverse(char **tab, int size)
{
    int i;

    for (i = 0; i != size - 1; i += 1)
        if (compare_words_reverse(tab[i], tab[i + 1]) == 2)
            tab = move_words(tab, i);
    return (tab);
}

char **sort_tab_reverse(char **tab, int size)
{
    while (!is_sorted_reverse(tab, size))
        tab = manage_tab_reverse(tab, size);
    return (tab);
}
