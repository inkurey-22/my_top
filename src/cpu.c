/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** cpu
*/

#include "my_top.h"

#include "my_strings.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void print_infos(__attribute__((unused)) char **cpu)
{
    printw("%%Cpu(s):  0.0 us,  0.0 sy,  0.0 ni, 100.0 id,");
    printw("  0.0 wa,  0.0 hi,  0.0 si,  0.0 st\n");
}

void print_cpu(void)
{
    FILE *fp = fopen("/proc/stat", "r");
    char *buff = malloc(sizeof(char) * (1024 + 1));
    size_t size = 0;
    char **cpu = NULL;

    if (fp == NULL || buff == NULL)
        return;
    size = fread(buff, 1024, 1, fp);
    if (size <= 0)
        return;
    buff[size] = '\0';
    cpu = split_string(buff, " ");
    if (cpu == NULL)
        return;
    print_infos(cpu);
    free(buff);
    for (int i = 0; cpu[i] != NULL; i++)
        free(cpu[i]);
    free(cpu);
}
