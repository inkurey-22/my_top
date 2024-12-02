/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** print processes
*/

#include <stddef.h>
#include <string.h>

#include "my_top.h"

void print_proc(const proc_t *proc, const int i)
{
    mvprintw(i, 0, "%7d", proc->pid);
    mvprintw(i, 7, " %-8s", proc->user);
    if (proc->pr > -100)
        mvprintw(i, 16, "%3d", proc->pr);
    else
        mvprintw(i, 16, "%3s", "rt");
    mvprintw(i, 19, "%4d", proc->ni);
    mvprintw(i, 23, "%8d", proc->virt);
    mvprintw(i, 31, "%7d", proc->res);
    mvprintw(i, 38, "%6d", proc->shr);
    mvprintw(i, 44, "%2c", proc->state);
    mvprintw(i, 46, " %-7s", proc->command);
}

void print_procs(list_t *procs, const char *user)
{
    list_t *tmp = procs;
    proc_t *proc = NULL;
    int line = 0;

    attron(A_STANDOUT);
    line = printw("\n%7s %-6s %4s %3s %7s %6s %5s %1s %s",
        "PID", "USER", "PR", "NI", "VIRT", "RES", "SHR", "S", "COMMAND");
    printw("%*s", COLS - line, "");
    attroff(A_STANDOUT);
    attron(A_NORMAL);
    for (int i = 7; tmp; i++) {
        proc = tmp->data;
        if (user == NULL || strcmp(user, proc->user) == 0)
            print_proc(proc, i);
        else
            i--;
        tmp = tmp->next;
    }
}
