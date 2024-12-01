/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** free_tab
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}
