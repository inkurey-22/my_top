/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** user
*/

#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_strings.h"

#include "my_top.h"

void parse_uid(char *buff, proc_t *proc)
{
    char **tab = split_string(buff, "\n");
    uid_t uid = 0;
    struct passwd *pwd = NULL;

    uid = atoi(tab[8] + 5);
    pwd = getpwuid(uid);
    if (pwd)
        proc->user = strdup(pwd->pw_name);
    else
        proc->user = my_strdup("?");
    free(buff);
    free_tab(tab);
}

void get_usr(proc_t *proc)
{
    char path[256];
    FILE *fp = NULL;
    size_t size = 0;
    char *buff = NULL;

    sprintf(path, "/proc/%d/status", proc->pid);
    fp = fopen(path, "r");
    if (!fp)
        return;
    buff = malloc(sizeof(char) * (1024 + 1));
    if (!buff)
        return;
    size = fread(buff, 1, 1024, fp);
    if (size <= 0)
        return;
    buff[size] = '\0';
    parse_uid(buff, proc);
    fclose(fp);
}
