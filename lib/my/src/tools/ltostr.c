/*
** EPITECH PROJECT, 2018
** Lib my
** File description:
** itoa.c
*/

#include <stdlib.h>

static char inttochar(int n)
{
    if (n >= 0 && n <= 9)
        return (n + '0');
    if (n >= 10 && n <= 10 + 26)
        return (n + 'A');
    return ('0');
}

static unsigned int nbrlen(int n, unsigned int base)
{
    unsigned int result = 0;

    while (n > 0) {
        result += 1;
        n = n / base;
    }
    return (result);
}

char *my_ltostr(int n, unsigned int base)
{
    char *result = NULL;
    unsigned int length;
    int sign = n < 0 ? 1 : 0;

    n = n >= 0 ? n : n * (-1);
    length = nbrlen(n, base);
    result = malloc(sizeof(char) * (length + 1 + sign));
    if (sign)
        result[0] = '-';
    if (!result)
        return (NULL);
    for (unsigned int i = 0; i < length; i += 1) {
        result[length - i - 1 + sign] = inttochar(n % base);
        n = n / base;
    }
    result[length + sign] = '\0';
    return (result);
}

char *my_itoa(int n)
{
    return (my_ltostr(n, 10));
}
