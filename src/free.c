/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** free
*/

#include "../include/malloc.h"

void move_brk()
{
    malloc_t *tmp_list = memory_map;
    void *init = sbrk(0);

    for (; tmp_list->_next != NULL ; tmp_list = tmp_list->_next);
    while (tmp_list->size > (long unsigned int)(2 * getpagesize())) {
        tmp_list -= 2 * getpagesize();
        brk((void *)(init - (2 * getpagesize())));
        init = sbrk(0);
    }
}

void free (void *ptr)
{
    malloc_t *tmp_list = memory_map;

    if (tmp_list == NULL)
        return;
    for (; tmp_list != NULL ; tmp_list = tmp_list->_next) {
        if ((void *)(tmp_list + 1) == ptr) {
            tmp_list->_status = UNUSED;
            break;
        }
    }
    merge_unused_node(&tmp_list);
    //move_brk();
}

//merge two unused block
void merge_unused_node(malloc_t **memory)
{
    malloc_t *temp = (*memory);

    if (temp == NULL || temp->_next == NULL)
        return; 
    while (temp->_next != NULL) {
        if (temp->_status == UNUSED && temp->_next->_status == UNUSED) {
            temp->size += temp->_next->size;
            temp->_next = temp->_next->_next;
        } else
        
            temp = temp->_next;
    }
    (*memory) = temp;
}
