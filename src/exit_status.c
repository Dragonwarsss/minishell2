/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** exit_status
*/

#include <stdio.h>
#include "my.h"

void print_exit_status(int stat)
{
    if (stat == 139) {
        my_puterr("Segmentation fault");
        my_printf("Segmentation fault\n");
    }
    if (stat == 136) {
        my_puterr("Floating exception");
        my_printf("Floating exception\n");
    }
}
