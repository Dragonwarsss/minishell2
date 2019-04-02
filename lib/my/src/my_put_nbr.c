/*
** EPITECH PROJECT, 2018
** Day03 Task07
** File description:
** my_put_nbr
*/

#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    int n = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }

    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    n = nb % 10;
    my_putchar(n + '0');
    return;
}
