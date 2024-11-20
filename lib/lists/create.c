/*
** EPITECH PROJECT, 2024
** C-lists_lib
** File description:
** create.c
*/

#include "my_lists.h"


/*
**  Creates a new node with the given data
*/
list_t *create_node(void *data)
{
    list_t *node = malloc(sizeof(list_t));

    if (node == NULL) {
        fprintf(stderr, "Error: node memory allocation failed\n");
    }
    node->data = data;
    node->next = NULL;
    return node;
}
