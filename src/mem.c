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

    printw("MiB Swap: %.1f total,  %.1f free,  %.1f used.  %.1f avail Mem\n",
        total, free, used, atof(mem[2] + 13) / 1024);
}

static void get_mem_infos(char **mem)
{
    const long total = atol(mem[0] + 9);
    const long free = atol(mem[1] + 8);
    const long available = atol(mem[2] + 13);
    const long buffers = atol(mem[3] + 9);
    const long cached = atol(mem[4] + 8);
    const long srec = atol(mem[25] + 13);
    const long used = total - available;
    const long buff_cache = buffers + cached + srec;

    printw("MiB Mem: %.1f total,  %.1f free,  %.1f used,  %.1f buff/cache\n",
        total / 1024.0, free / 1024.0, used / 1024.0, buff_cache / 1024.0);
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
