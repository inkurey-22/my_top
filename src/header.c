/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** header
*/

#include "my_top.h"

#include <time.h>
#include <stdlib.h>
#include <string.h>

#include <ncurses.h>

static int find_state(list_t *procs, char state)
{
    list_t *tmp = procs;
    proc_t *proc = NULL;
    int count = 0;

    for (; tmp; tmp = tmp->next) {
        proc = tmp->data;
        if (proc->state == state)
            count++;
    }
    return count;
}

static void print_users(void)
{
    FILE *fp = fopen("/var/run/utmp", "r");
    char buf[128];
    int users = 0;

    if (fp == NULL)
        return;
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        if (buf[0] != '\0')
            users++;
    }
    fclose(fp);
    printw("%d user%s, ", users, users > 1 ? "s" : "");
}

void top_line(void)
{
    printw("top - ");
    print_time();
    print_uptime();
    print_users();
    print_loadavg();
}

void line_two(list_t *procs)
{
    int nb_procs = list_size(procs);
    int run = find_state(procs, 'R');
    int stopped = find_state(procs, 'T');
    int zombie = find_state(procs, 'Z');
    int sleep = nb_procs - run;

    printw("Tasks: %d total,  %d running,  %d sleeping", nb_procs, run, sleep);
    printw(",  %d stopped,  %d zombie\n", stopped, zombie);
}

void print_header(list_t *procs)
{
    top_line();
    line_two(procs);
    print_cpu();
    print_mem();
}
