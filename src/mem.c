/*
** EPITECH PROJECT, 2024
** my top
** File description:
** mem
*/

#include "my_top.h"

#include "my_strings.h"

static void get_swap_infos(char **mem)
{
    const double total = atof(mem[14] + 10) / 1024;
    const double free = atof(mem[15] + 9) / 1024;
    const double used = total - free;

    printw("MiB Swap: %.1f total,  %.1f free,  %.1f used,  %.1f avail Mem\n",
        total, free, used, atof(mem[2] + 13) / 1024);
}

static void get_mem_infos(char **mem)
{
    const double total = atof(mem[0] + 9) / 1024;
    const double free = atof(mem[1] + 8) / 1024;
    const double available = atof(mem[2] + 13) / 1024;
    const double buffers = atof(mem[3] + 9) / 1024;
    const double cached = atof(mem[4] + 8) / 1024;
    const double srec = atof(mem[25] + 13) / 1024;
    const double used = total - available;
    const double buff_cache = buffers + cached + srec;

    printw("MiB Mem: %.1f total,  %.1f free,  %.1f used,  %.1f buff/cache\n",
        total, free, used, buff_cache);
}

void print_mem(void)
{
    FILE *fp = fopen("/proc/meminfo", "r");
    char *buff = malloc(sizeof(char) * 4096);
    size_t size = 0;
    char **mem = NULL;

    if (fp == NULL || buff == NULL)
        return;
    size = fread(buff, 1, 4096, fp);
    if (size <= 0)
        return;
    buff[size] = '\0';
    mem = split_string(buff, "\n");
    if (mem == NULL)
        return;
    free(buff);
    get_mem_infos(mem);
    get_swap_infos(mem);
    for (int i = 0; mem[i] != NULL; i++)
        free(mem[i]);
    free(mem);
}
