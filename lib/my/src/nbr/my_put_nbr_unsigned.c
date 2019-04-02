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

void my_put_nbr_unsigned(unsigned int nb)
{
    int n = 0;

    if (nb > 9) {
        my_put_nbr_unsigned(nb / 10);
    }
    n = nb % 10;
    my_putchar(n + '0');
    return;
}
