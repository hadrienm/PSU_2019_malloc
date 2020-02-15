/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** realoc
*/

#include "../include/malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *new_ptr = NULL;

    if (ptr == NULL)
        return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    new_ptr = malloc(size);
    memcpy(new_ptr, ptr, size);
    free(ptr);
    return (new_ptr);
}

void *realloc_array(void *ptr, size_t size)
{
    void *new_ptr = NULL;
    malloc_t *tmp_ptr = ptr; 

    if (ptr == NULL)
        return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    new_ptr = calloc(tmp_ptr->size , size);
    memcpy(new_ptr, ptr, size);
    free(ptr);
    return (new_ptr);
}
