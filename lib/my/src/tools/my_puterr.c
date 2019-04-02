/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_puterr
*/

#include <unistd.h>
#include "my.h"

void my_puterr(char *str)
{
    write(2, str, my_strlen(str));
}
