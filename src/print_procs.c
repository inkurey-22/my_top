/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** print processes
*/

#include <stddef.h>

#include "my_top.h"

void print_proc(proc_t *proc, int i)
{
    mvprintw(i, 0, "%7d", proc->pid);
    mvprintw(i, 7, "%5d", proc->pr);
    mvprintw(i, 12, "%4d", proc->ni);
    mvprintw(i, 16, "%8d", proc->virt);
    mvprintw(i, 24, "%7d", proc->res);
    mvprintw(i, 31, "%6d", proc->shr);
    mvprintw(i, 37, "%2c", proc->state);
    mvprintw(i, 39, " %s", proc->command);
}

void print_procs(list_t *procs, WINDOW *win)
{
    list_t *tmp = procs;
    proc_t *proc = NULL;
    int line = 0;

    attron(A_STANDOUT);
    line = printw("\n%7s %4s %3s %7s %6s %5s %1s %s",
        "PID", "PR", "NI", "VIRT", "RES", "SHR", "S", "COMMAND");
    printw("%*s", COLS - line, "");
    attroff(A_STANDOUT);
    attron(A_NORMAL);
    for (int i = 7; tmp; i++) {
        proc = tmp->data;
        print_proc(proc, i);
        tmp = tmp->next;
    }
}
