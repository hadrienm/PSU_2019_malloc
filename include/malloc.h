/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef enum status_s
{
    UNUSED,
    USED
}status_t;

typedef struct malloc_s
{
    struct malloc_s *_next;
    size_t size;
    status_t _status;
}malloc_t;

extern malloc_t *memory_map;

void free (void *ptr);
void *get_ptr(size_t size);
void *add_inside_list(size_t size);
void *init(size_t size);
void *put_end(size_t size);
void merge_unused_node(malloc_t **memory_map);
bool found_unused_node(size_t size);
int total_used_size();
int count_number_of_node();
#endif /* !MALLOC_H_ */
