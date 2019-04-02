/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** sort_tab
*/

#include <stdlib.h>
#include "my.h"

char **move_words(char **tab, int i)
{
    char *tmp = my_strdup(tab[i]);
    char *tmp2 = my_strdup(tab[i + 1]);

    free(tab[i]);
    free(tab[i + 1]);
    tab[i] = tmp2;
    tab[i + 1] = tmp;
    return (tab);
}

char **manage_tab(char **tab, int size)
{
    int i;

    for (i = 0; i != size - 1; i += 1)
        if (compare_words(tab[i], tab[i + 1]) == 2)
            tab = move_words(tab, i);
    return (tab);
}

char **sort_tab(char **tab, int size)
{
    while (!is_sorted(tab, size))
        tab = manage_tab(tab, size);
    return (tab);
}
