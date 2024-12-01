/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** print processes
*/

#include <stddef.h>

#include "my_top.h"

void print_procs(list_t *procs, WINDOW *win)
{
    list_t *tmp = procs;
    proc_t *proc = NULL;
    int line = 0;

    attron(A_STANDOUT);
    line = printw("\n%7s %4s %3s %5s %1s %s",
        "PID", "PR", "NI", "SHR", "S", "COMMAND");
    printw("%*c", getmaxx(win) - line, ' ');
    attroff(A_STANDOUT);
    move(2, 0);
    for (int i = 7; tmp; i++) {
        proc = tmp->data;
        mvprintw(i, 0, "%7d %4d %3d %5d %1c %s", proc->pid, proc->pr,
            proc->ni, proc->shr, proc->state, proc->command);
        tmp = tmp->next;
    }
}
