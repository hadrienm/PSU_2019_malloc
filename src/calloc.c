/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** calloc
*/

#include "../include/malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void* elm = NULL;
    size_t total;

    total = nmemb * size;
    if (total == 0)
        return NULL;
    elm = malloc(total);
    if (elm == NULL)
        return (NULL);
    return (memset(elm, 0, total));
}
