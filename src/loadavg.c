/*
** EPITECH PROJECT, 2024
** bsmytop
** File description:
** my_getloadavg
*/

#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>

#include "my_top.h"

void print_loadavg(void)
{
    double loadavg[3] = {0.0, 0.0, 0.0};
    FILE *fp = fopen("/proc/loadavg", "r");
    int count = 0;

    if (fp == NULL)
        return;
    count = fscanf(fp, "%lf %lf %lf", &loadavg[0], &loadavg[1],
        &loadavg[2]);
    fclose(fp);
    if (count < 1)
        printw("load average: N/A\n");
    if (count == 1)
        printw("load average: %.2f\n", loadavg[0]);
    if (count == 2)
        printw("load average: %.2f, %.2f\n", loadavg[0], loadavg[1]);
    if (count == 3)
        printw("load average: %.2f, %.2f, %.2f\n", loadavg[0], loadavg[1],
            loadavg[2]);
}
