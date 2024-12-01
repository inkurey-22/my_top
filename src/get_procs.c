/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** get processes infos
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

#include "my_lists.h"
#include "my_strings.h"

#include "my_top.h"

void parse_shr_tab(char *buff, int *shr)
{
    char **tab = split_string(buff, "\n");

    if (!tab)
        return;
    for (int i = 0; tab[i]; i++)
        if (my_strncmp("RssShmem", tab[i], 8) == 0)
            *shr = atoi(tab[i] + 10);
    free_tab(tab);
    free(buff);
}

int get_shr(int pid)
{
    int shr = 0;
    char path[256];
    FILE *fp = NULL;
    char *buff = NULL;
    size_t len = 0;

    sprintf(path, "/proc/%d/statm", pid);
    fp = fopen(path, "r");
    buff = malloc(sizeof(char) * (1024 + 1));
    if (!fp || !buff)
        return 0;
    len = fread(buff, 1, 1024, fp);
    if (len <= 0)
        return 0;
    buff[len] = '\0';
    parse_shr_tab(buff, &shr);
    return shr;
}

void parse_proc_infos(proc_t *proc, const char *buff)
{
    char **tab = split_string(buff, "( )");

    if (!tab)
        return;
    proc->state = tab[2][0];
    proc->command = my_strdup(tab[1]);
    proc->pr = atoi(tab[17]);
    proc->ni = atoi(tab[18]);
    proc->shr = get_shr(proc->pid);
    free_tab(tab);
}

void get_proc_infos(proc_t *proc)
{
    char path[256];
    FILE *fp = NULL;
    char *buff = NULL;
    size_t len = 0;

    sprintf(path, "/proc/%d/stat", proc->pid);
    fp = fopen(path, "r");
    if (!fp)
        return;
    buff = malloc(sizeof(char) * (1024 + 1));
    if (!buff)
        return;
    len = fread(buff, 1, 1024, fp);
    if (len <= 0)
        return;
    buff[len] = '\0';
    parse_proc_infos(proc, buff);
    fclose(fp);
    free(buff);
}

list_t *get_procs(list_t *procs)
{
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    proc_t *proc = NULL;

    if (!dir)
        return NULL;
    do {
        entry = readdir(dir);
        if (entry && atoi(entry->d_name) != 0) {
            proc = malloc(sizeof(proc_t));
            proc->pid = atoi(entry->d_name);
            get_proc_infos(proc);
            append_node(&procs, proc);
        }
    } while (entry);
    closedir(dir);
    return procs;
}
