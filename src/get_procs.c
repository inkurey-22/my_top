/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** get processes infos
*/

#include "my_lists.h"

#include "my_top.h"

void parse_infos(char **infos, list_t *list)
{
    proc_t *proc = malloc(sizeof(proc_t));

    if (proc == NULL)
        return;
    proc->pid = atoi(infos[0]);
    proc->name = infos[1];
    proc->state = infos[2];
    proc->ppid = atoi(infos[3]);
    proc->priority = atoi(infos[17]);
    proc->nice = atoi(infos[18]);
    proc->vsize = atoi(infos[22]);
    proc->rss = atoi(infos[23]);
    add_node(list, proc);
}

void get_proc(char *path, list_t *list)
{
    FILE *file = fopen(path, "r");
    char *line = malloc(sizeof(char) * 1024);
    char **infos = NULL;

    if (file == NULL)
        return;
    if (line == NULL)
        return;
    memset(line, 0, 1024);
    fgets(line, 1024, file);
    infos = split_string(line, " ");
    parse_infos(infos, list);
}

list_t *get_proc_list(void)
{
    list_t *list = NULL;
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    char path[256];
    int pid = 0;

    do {
        entry = readdir(dir);
        if (entry == NULL)
            break;
        pid = atoi(entry->d_name);
        if (pid == 0)
            continue;
        sprintf(path, "/proc/%d/stat", pid);
        get_proc(path, list);
    } while (entry != NULL);
}
