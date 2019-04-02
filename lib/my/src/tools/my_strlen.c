/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return (0);
    for (; str[i]; i += 1);
    return (i);
}
