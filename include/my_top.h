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

typedef struct coords_s {
    int x;
    int y;
} coords_t;

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
    char *time;
    char *command;
} proc_t;

void print_header(void);
void print_time(void);
void print_uptime(void);
void print_loadavg(void);
void print_cpu(void);
void print_mem(void);

#endif /* !MY_TOP_H_ */
