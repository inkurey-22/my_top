/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** get_procs
*/

#include <stdio.h>
#include <dirent.h>

#include "my_lists.h"
#include "my_strings.h"

#include "my_top.h"

void parse_memory_tab(proc_t *proc, char *buff)
{
    char **tab = split_string(buff, " ");

    if (!tab)
        return;
    proc->virt = atoi(tab[0]);
    proc->res = atoi(tab[1]);
    proc->shr = atoi(tab[2]);
    free_tab(tab);
    free(buff);
}

void get_memories(proc_t *proc)
{
    char path[256];
    FILE *fp = NULL;

    sprintf(path, "/proc/%d/statm", proc->pid);
    fp = fopen(path, "r");
    if (!fp)
        return;
    fscanf(fp, "%d %d %d", &proc->virt, &proc->res, &proc->shr);
    proc->virt *= 4;
    proc->res *= 4;
    proc->shr *= 4;
    fclose(fp);
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
    get_usr(proc);
    get_memories(proc);
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
