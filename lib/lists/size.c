/*
** EPITECH PROJECT, 2024
** C-lists_lib
** File description:
** size.c
*/

#include "my_lists.h"

/*
**  Returns the size of the list
*/
int list_size(list_t *list)
{
    int size = 0;

    while (list) {
        size++;
        list = list->next;
    }
    return size;
}
