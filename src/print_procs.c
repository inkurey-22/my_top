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

    printw("PID PR NI VIRT RES S COMMAND\n");
    /*
    while (tmp) {
        proc = tmp->data;
        printw("%d %d %d %d %d %c %s\n", proc->pid, proc->pr, proc->ni,
            proc->virt, proc->res, proc->state, proc->command);
        tmp = tmp->next;
    }*/
}
