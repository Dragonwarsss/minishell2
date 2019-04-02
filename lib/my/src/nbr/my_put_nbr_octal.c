/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** put a number
*/

void my_putchar(char c);

void my_put_nbr_octal(int nb)
{
    if (nb >= 0 && nb <= 7) {
        my_putchar(nb + 48);
    }
    if (nb > 7) {
        my_put_nbr_octal(nb / 8);
        my_put_nbr_octal(nb % 8);
    }
}
