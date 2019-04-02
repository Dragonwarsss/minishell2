/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** put a number
*/

void my_putchar(char c);

void my_put_nbr_binary(int nb)
{
    if (nb >= 0 && nb <= 1)
        my_putchar(nb + 48);
    else if (nb > 1) {
        my_put_nbr_binary(nb / 2);
        my_put_nbr_binary(nb % 2);
    }
}
