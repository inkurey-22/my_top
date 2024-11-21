/*
** EPITECH PROJECT, 2024
** bsmytop
** File description:
** my_getloadavg
*/

#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>

void print_loadavg(void)
{
    double loadavg[3];
    FILE *fp = fopen("/proc/loadavg", "r");

    if (fp == NULL)
        return;
    fscanf(fp, "%lf %lf %lf", &loadavg[0], &loadavg[1], &loadavg[2]);
    fclose(fp);
    printw("load average: %.2f, %.2f, %.2f\n",
        loadavg[0], loadavg[1], loadavg[2]);
}
