/*
** EPITECH PROJECT, 2024
** base
** File description:
** main
*/

#include <errno.h>
#include <string.h>
#include <signal.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

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
    if (ch == 'k')
        launch_kill();
    return 0;
}

void launch_top(const flags_t *flags)
{
    list_t *procs = NULL;

    for (int i = 0; i != flags->frames; i++) {
        procs = get_procs(procs);
        print_header(procs);
        print_procs(procs, flags->user);
        free_procs(procs);
        procs = NULL;
        if (check_inputs()) {
            endwin();
            return;
        }
        clear();
    }
}

void get_flags(const int ac, char **av, flags_t *flags)
{
    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "-u") == 0 && i + 1 < ac)
            flags->user = av[i + 1];
        if (strcmp(av[i], "-d") == 0 && i + 1 < ac)
            flags->delay = atoi(av[i + 1]);
        if (strcmp(av[i], "-s") == 0 && i + 1 < ac)
            flags->frames = atoi(av[i + 1]);
    }
}

int main(int ac, char **av)
{
    flags_t flags = {NULL, 3, -1};

    get_flags(ac, av, &flags);
   	initscr();
    if (has_colors() == FALSE) {
        endwin();
        return 84;
    }
    curs_set(0);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    timeout(1000 * flags.delay);
    launch_top(&flags);
    endwin();
    return 0;
}
