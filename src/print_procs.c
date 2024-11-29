/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** print processes
*/

#include "my_top.h"

void print_procs(list_t *procs)
{
    list_t *tmp = procs;
    proc_t *proc = NULL;

    attron(COLOR_PAIR(1));
    printw("\n%7s  %4s %4s %2s  %s", "PID", "PR", "NI", "S", "COMMAND");
    attroff(COLOR_PAIR(1));
    for (int i = 7; tmp; i++) {
        proc = tmp->data;
        mvprintw(i, 0, "%7d  %4d %4d %2c  %s", proc->pid, proc->pr, proc->ni,
            proc->state, proc->command);
        tmp = tmp->next;
    }
}
