/*
** EPITECH PROJECT, 2018
** Printf
** File description:
** recoding printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void print(void) __attribute__ ((destructor));

void my_putchar(int nb)
{
    char c = nb;

    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i += 1);
    write(1, str, i);
}

void is_ptr(char c)
{
    if (c == 'p')
        write(1, "0x", 2);
}

void list(va_list arg, function_t *fnc, char *str, int i)
{
    function_t *tmp = fnc;
    int nb;

    while (tmp != NULL) {
        if (str[i] == tmp->c && str[i]) {
            is_ptr(str[i]);
            nb = va_arg(arg, int);
            tmp->ptr(nb);
            break;
        }
        if (str[i] == 's') {
            my_putstr(va_arg(arg, char*));
            break;
        }
        tmp = tmp->next;
    }

}

void my_printf(char *str, ...)
{
    function_t *fnc = create_ll();
    int i = 0;
    va_list arg;

    if (!fnc)
        return;
    va_start(arg, str);
    while (str[i]) {
        if (str[i] != '%')
            my_putchar(str[i]);
        else if (str[i] == '%' && str[i + 1] == '%') {
            write(1, "%", 1);
            i += 1;
        }
        else {
            i += 1;
            list(arg, fnc, str, i);
        }
        i += 1;
    }
    free_ll(fnc);
}
