/*
** EPITECH PROJECT, 2024
** bsmytop
** File description:
** my_getloadavg
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int my_getloadavg(double loadavg[], int nelem)
{
    FILE *fp = fopen("/proc/loadavg", "r");

    if (fp == NULL)
        return -1;
    if (nelem == 1)
        fscanf(fp, "%lf", &loadavg[0]);
    if (nelem == 2)
        fscanf(fp, "%lf %lf", &loadavg[0], &loadavg[1]);
    if (nelem >= 3)
        fscanf(fp, "%lf %lf %lf", &loadavg[0], &loadavg[1], &loadavg[2]);
    return 0;
}
