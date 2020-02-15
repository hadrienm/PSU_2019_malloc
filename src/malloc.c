/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** main
*/

#include "../include/malloc.h"

malloc_t *memory_map = NULL;

//TODO: malloc - https://trello.com/c/I9RuvtK4/1-malloc

//find smaller size possible
void *get_ptr(size_t size)
{
    malloc_t *list = memory_map;
    malloc_t *ptr = NULL;

    for (; list != NULL; list = list->_next) {
        if (list->_status == UNUSED && list->size >= size) {
            if (list->size == size)
                return (list);
            else if (ptr == NULL)
                ptr = list;
            else if (list->size < ptr->size)
                ptr = list;
        }
    }
    return ptr;
}

//main function of malloc
void *malloc(size_t size)
{
    for (; size % 16 != 0; ++size);
    if (memory_map == NULL) {
        return init(size);
    } else if (found_unused_node(size) == true) {
        return add_inside_list(size);
    } else {
        return put_end(size);
    }
}
