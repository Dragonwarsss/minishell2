/*
** EPITECH PROJECT, 2018
** Lib my
** File description:
** my_strtol.c
*/

#include "my.h"
#include "is.h"

static int to_num(int c, int base, int *test)
{
    int result = 0;

    if (MY_ISDIGIT(c))
        result = c - '0';
    else if (MY_ISUPPER(c))
        result = c - 'A' + 10;
    else if (MY_ISLOWER(c))
        result = c - 'a' + 10;
    if (result >= base) {
        *test = 0;
        return (0);
    }
    return (result);
}

int my_strtol(char *s, int base)
{
    int result = 0;
    int sign = 1;
    unsigned int i = 0;
    int test = 1;

    while (MY_ISSPACE(s[i]))
        i += 1;
    if (s[i] == '-') {
        sign = -1;
        i += 1;
    }
    else if (!MY_ISALNUM(s[i]) && s[i] != '+')
        return (0);
    while (MY_ISALNUM(s[i]) && test) {
        result = (result * base) + to_num(s[i], base, &test);
        i += 1;
    }
    return (result * sign);
}

int my_atoi(char *s)
{
    return (my_strtol(s, 10));
}
