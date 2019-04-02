/*
** EPITECH PROJECT, 2018
** printf
** File description:
** print modulo
*/

#include <unistd.h>

void print_mod(int nb)
{
    char c = nb;
    c = '%';

    write(1, &c, 1);
}
