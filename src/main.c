/*
** EPITECH PROJECT, 2024
** base
** File description:
** main
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

#include "my_printf.h"

#include "my_top.h"

static void free_procs(list_t *procs)
{
    list_t *tmp = procs;
    proc_t *proc = NULL;

    for (; tmp; tmp = tmp->next) {
        proc = tmp->data;
        free(proc->command);
        free(proc->user);
        free(proc);
    }
}

int check_inputs(void)
{
    const int ch = getch();

    if (ch == 'q')
        return 1;
    return 0;
}

void launch_top(void)
{
    list_t *procs = NULL;

    while (1) {
        procs = get_procs(procs);
        print_header(procs);
        print_procs(procs);
        free_procs(procs);
        procs = NULL;
        if (check_inputs()) {
            endwin();
            return;
        }
        clear();
    }
}

int main(void)
{
   	initscr();
    if (has_colors() == FALSE) {
        endwin();
        return 84;
    }
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    timeout(3000);
    launch_top();
    endwin();
    return 0;
}
