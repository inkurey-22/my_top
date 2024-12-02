/*
** EPITECH PROJECT, 2024
** bsmytop
** File description:
** my_top
*/
#ifndef MY_TOP_H_
    #define MY_TOP_H_

    #include "my_lists.h"

    #include <ncurses.h>

typedef struct proc_s {
    int pid;
    int pr;
    int ni;
    int virt;
    int res;
    int shr;
    char state;
    double cpu;
    double mem;
    char *user;
    char *time;
    char *command;
} proc_t;

void print_header(list_t *procs);
void print_time(void);
void print_uptime(void);
void print_loadavg(void);
void print_cpu(void);
void print_mem(void);
void print_procs(list_t *procs);

list_t *get_procs(list_t *procs);
void get_usr(proc_t *proc);

#endif /* !MY_TOP_H_ */
