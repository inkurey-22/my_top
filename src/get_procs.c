/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** get processes infos
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

#include "my_lists.h"
#include "my_strings.h"

#include "my_top.h"

void parse_proc_infos(proc_t *proc, char *buff)
{
    char **tab = split_string(buff, "( )");

    if (!tab)
        return;
    proc->state = tab[2][0];
    proc->command = my_strdup(tab[1]);
    proc->pr = atoi(tab[17]);
    proc->ni = atoi(tab[18]);
    proc->virt = atoi(tab[22]);
    proc->res = atoi(tab[23]);
}

void get_proc_infos(proc_t *proc)
{
    char path[256];
    int fd = 0;
    char *buff = NULL;
    size_t len = 0;

    sprintf(path, "/proc/%d/stat", proc->pid);
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return;
    buff = malloc(1024);
    if (!buff)
        return;
    printw("Coucou");
    len = read(fd, buff, 1024);
    printw("Autre coucou");
    if (len <= 0)
        return;
    buff[len] = '\0';
    printw("%s\n", buff);
    parse_proc_infos(proc, buff);
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
            if (!proc)
                return NULL;
            proc->pid = atoi(entry->d_name);
            get_proc_infos(proc);
            append_node(&procs, proc);
        }
    } while (entry);
    closedir(dir);
    return procs;
}
