/*
** EPITECH PROJECT, 2019
** my_malloc
** File description:
** exit if NULL
*/

#include <stdlib.h>
#include <stddef.h>

void *my_malloc(size_t size)
{
    void *ptr = malloc(size);

    if (!ptr)
        exit(84);
    return (ptr);
}
