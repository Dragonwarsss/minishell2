/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** display_env
*/

#include "my.h"
#include "env.h"

void display_env(void)
{
    int i;

    for (i = 0; envp[i]; i += 1)
        my_printf("%s\n", envp[i]);
    for (i = 0; var[i].name; i += 1) {
        my_putstr(var[i].name);
        my_putchar('=');
        if (var[i].value)
            my_putstr(var[i].value);
        my_putchar('\n');
    }
}
