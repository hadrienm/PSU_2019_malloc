/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** list
*/

#include "../include/malloc.h"

//Init link list
void *init(size_t size)
{
    size_t pagesize = 2 * getpagesize();

    for (; size + sizeof(malloc_t) >= pagesize; pagesize += 2 * getpagesize());
    memory_map = sbrk(pagesize);
    if (memory_map == (void *) -1)
        return NULL;
    memory_map->size = pagesize - sizeof(malloc_t);
    memory_map->_status = USED;
    memory_map->_next = NULL;
    if (memory_map->size > sizeof(malloc_t) + size) {
        memory_map->size = size;
        memory_map->_next = (void *)(memory_map + 1) + size;
        memory_map->_next->_status = UNUSED;
        memory_map->_next->size = pagesize - size - 2 * sizeof(malloc_t);
        memory_map->_next->_next = NULL;
    }
    return (memory_map + 1);
}

//Add node at end of link list
void *put_end(size_t size)
{
    size_t pagesize = 2 * getpagesize();
    void *tmp = NULL;
    malloc_t *memory = memory_map;

    for (; size + sizeof(malloc_t) >= pagesize; pagesize += 2 * getpagesize());
    tmp = sbrk(pagesize);
    if (tmp == (void *) -1) return NULL;
    for (; memory->_next != NULL; memory = memory->_next);
    memory->_next = (void *)(memory + 1) + memory->size;
    memory = memory->_next;
    memory->size = pagesize - sizeof(malloc_t);
    memory->_status = USED;
    memory->_next = NULL;
    if (memory_map->size - size > sizeof(malloc_t)) {
        memory->size = size;
        memory->_next = (void *)(memory + 1) + memory->size;
        memory->_next->_status = UNUSED;
        memory->_next->size = pagesize - size - 2 * sizeof(malloc_t);
        memory->_next->_next = NULL;
    }
    return (memory + 1);
}

//add new node inside the link list
void *add_inside_list(size_t size)
{
    malloc_t *tmp_list = memory_map;
    malloc_t *save = NULL;
    size_t max_size = 0;

    tmp_list = get_ptr(size);
    save = tmp_list->_next;
    max_size = tmp_list->size;
    if (max_size == size) {
        tmp_list->_status = USED;
        return (tmp_list + 1);
    }
    if (max_size - size > sizeof(malloc_t)) {
        tmp_list->_status = USED;
        tmp_list->size = size;
        tmp_list->_next = (void *)(tmp_list + 1) + size;
        tmp_list->_next->size = max_size - tmp_list->size - sizeof(malloc_t);
        tmp_list->_next->_status = UNUSED;
        tmp_list->_next->_next = save;
    } else
        return put_end(size);
    return tmp_list + 1;
}

//check if a node is empty and she's can contain the new node
bool found_unused_node(size_t size)
{
    malloc_t *tmp_list = memory_map;

    if (tmp_list == NULL)
        return false;
    for (; tmp_list != NULL; tmp_list = tmp_list->_next)
        if (tmp_list->_status == UNUSED && tmp_list->size >= size)
            return true;
    return false;
}
