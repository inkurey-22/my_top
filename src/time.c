/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** print time and uptime
*/

#include "my_top.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <ncurses.h>

void print_time(void)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];

    strftime(s, sizeof(s), "%H:%M:%S", tm);
    printw(s);
}

static void format_uptime(char *uptime)
{
    int seconds = atoi(uptime);
    int days = seconds / 86400;
    int hours = (seconds % 86400) / 3600;
    int minutes = (seconds % 3600) / 60;

    mvprintw(0, 15, "up ");
    if (days > 0)
        printw("%d day%s,", days, days > 1 ? "s" : "");
    if (hours > 0)
        printw(" %d:%02d, ", hours, minutes);
    else
        printw("%d min, ", minutes);
}

void print_uptime(void)
{
    FILE *fp = fopen("/proc/uptime", "r");
    char buf[128];
    char *uptime;

    if (fp == NULL)
        return;
    fgets(buf, sizeof(buf), fp);
    fclose(fp);
    uptime = strtok(buf, " ");
    format_uptime(uptime);
}
