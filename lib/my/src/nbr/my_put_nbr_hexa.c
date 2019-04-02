/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** put a number
*/

void my_putchar(char);

void my_put_nbr_hexa(int nb)
{
    if (nb < 10)
        my_putchar(nb + 48);
    else if (nb < 16)
        my_putchar(nb + 87);
    else {
        my_put_nbr_hexa(nb / 16);
        my_put_nbr_hexa(nb % 16);
    }
}
