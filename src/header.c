/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** header
*/

#include "my_top.h"

#include <time.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include <ncurses.h>
#include <bits/fcntl-linux.h>

static int find_state(list_t *procs, char state)
{
    const list_t *tmp = procs;
    const proc_t *proc = NULL;
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
    const int fd = open("/var/run/utmp", O_RDONLY);
    struct utmp user;
    int users = 0;

    if (fd < 0) {
        printw("0 user, ");
        return;
    }
    while (read(fd, &user, sizeof(struct utmp)) > 0) {
        if (user.ut_type == USER_PROCESS)
            users++;
    }
    close(fd);
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
    int sleep = nb_procs - run - zombie - stopped;

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
