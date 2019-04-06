/*
** EPITECH PROJECT, 2018
** printf
** File description:
** linked list
*/

#include <stdlib.h>
#include "my.h"

void free_ll(function_t *fnc)
{
    function_t *current;
    function_t *tmp = fnc;

    while (fnc) {
        current = fnc;
        fnc = current->next;
        free(current);
    }
}

function_t *push_ll(function_t *fnc, char c)
{
    function_t *tmp = malloc(sizeof(function_t));

    if (!tmp)
        return (NULL);
    tmp->c = c;
    if (fnc != NULL)
        tmp->next = fnc;
    else
        tmp->next = NULL;
    return (tmp);
}

function_t *create_ll_3(function_t *fnc)
{
    fnc = push_ll(fnc, 'u');
    if (!fnc)
        return (NULL);
    fnc->ptr = &my_put_nbr_unsigned;
    return (fnc);
}

function_t *create_ll_2(function_t *fnc)
{
    fnc = push_ll(fnc, 'x');
    if (!fnc)
	return (NULL);
    fnc->ptr = &my_put_nbr_hexa;
    fnc = push_ll(fnc, 'X');
    if (!fnc)
        return (NULL);
    fnc->ptr = &my_put_nbr_hexaup;
    fnc = push_ll(fnc, 'b');
    if (!fnc)
        return (NULL);
    fnc->ptr = &my_put_nbr_binary;
    fnc = push_ll(fnc, 'p');
    if (!fnc)
        return (NULL);
    fnc->ptr = &my_put_ptr;
    fnc = create_ll_3(fnc);
    return (fnc);
}

function_t *create_ll(void)
{
    function_t *fnc;

    fnc = push_ll(NULL, 'i');
    if (!fnc)
        return (NULL);
    fnc->ptr = &my_put_nbr;
    fnc = push_ll(fnc, 'd');
    if (!fnc)
        return (NULL);
    fnc->ptr = &my_put_nbr;

    fnc = push_ll(fnc, 'c');
    if (!fnc)
        return (NULL);
    fnc->ptr = &my_putchar;
    fnc = push_ll(fnc, 'o');
    if (!fnc)
        return (NULL);
    fnc->ptr = &my_put_nbr_octal;
    fnc = create_ll_2(fnc);
    return (fnc);
}
