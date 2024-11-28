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

void line_two(void)
{
    printw("Tasks: 000 total,  0 running, 000 sleeping,");
    printw("   0 stopped,   0 zombie\n");
}

void print_header(void)
{
    top_line();
    line_two();
    print_cpu();
    print_mem();
}
