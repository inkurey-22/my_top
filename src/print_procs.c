/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** print processes
*/

#include <stddef.h>

#include "my_top.h"

void print_proc(const proc_t *proc, const int i)
{
    mvprintw(i, 0, "%7d", proc->pid);
    mvprintw(i, 8, "%-8s", proc->user);
    if (proc->pr > -100)
        mvprintw(i, 16, "%4d", proc->pr);
    else
        mvprintw(i, 16, "%4s", "rt");
    mvprintw(i, 21, "%3d", proc->ni);
    mvprintw(i, 25, "%7d", proc->virt);
    mvprintw(i, 33, "%6d", proc->res);
    mvprintw(i, 40, "%5d", proc->shr);
    mvprintw(i, 47, "%1c", proc->state);
    mvprintw(i, 49, "%s", proc->command);
}

void print_procs(list_t *procs)
{
    list_t *tmp = procs;
    proc_t *proc = NULL;
    int line = 0;

    attron(A_STANDOUT);
    line = printw("\n%7s %-8s %4s %3s %7s %6s %5s %1s %s",
        "PID", "USER", "PR", "NI", "VIRT", "RES", "SHR", "S", "COMMAND");
    printw("%*s", COLS - line, "");
    attroff(A_STANDOUT);
    attron(A_NORMAL);
    for (int i = 7; tmp; i++) {
        proc = tmp->data;
        print_proc(proc, i);
        tmp = tmp->next;
    }
}
