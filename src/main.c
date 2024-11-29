/*
** EPITECH PROJECT, 2024
** base
** File description:
** main
*/

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
        free(proc);
    }
}

void check_inputs(void)
{
    const int ch = getch();

    if (ch == 'q'){
        endwin();
        exit(0);
    }
}

void launch_top(WINDOW *win)
{
    list_t *procs = NULL;

    while (1) {
        procs = get_procs(procs);
        print_header(procs);
        print_procs(procs, win);
        free_procs(procs);
        procs = NULL;
        check_inputs();
        clear();
    }
}

int main(void)
{
    WINDOW *win = initscr();

    if (has_colors() == FALSE) {
        endwin();
        return 84;
    }
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    timeout(3000);
    launch_top(win);
    endwin();
    return 0;
}
