/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** exit_status
*/

#include <stdio.h>
#include "my.h"

void print_exit_status(char *str)
{
    if (my_strcomp(str, "Floating point exception"))
        my_puterr("Floating exception");
    if (my_strcomp(str, "Segmentation fault"))
        my_puterr("Segmentation fault");
}
