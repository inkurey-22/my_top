/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** kill
*/

#include <signal.h>

#include "my_top.h"

void manage_signal(const int pid)
{
    int sig = 0;
    char sig_str[10];

    mvprintw(5, 0, "Enter signal to send to %d : ", pid);
    echo();
    getnstr(sig_str, 10);
    noecho();
    sig = atoi(sig_str);
    if (sig > 0) {
        if (kill(pid, sig) == 0)
            mvprintw(5, 0, "Signal %d sent to process %d successfully. Press any key to continue.", sig, pid);
        else
            mvprintw(5, 0, "Failed to send signal %d to process %d. Press any key to continue.", sig, pid);
    } else
        mvprintw(5, 0, "Invalid signal. Press any key to continue.");
}

void launch_kill(void)
{
    int pid = 0;
    char pid_str[10];

    mvprintw(5, 0, "Enter PID to kill : ");
    echo();
    getnstr(pid_str, 10);
    noecho();
    pid = atoi(pid_str);
    if (pid > 0)
        manage_signal(pid);
    else
        mvprintw(5, 0, "Invalid PID. Press any key to continue.");
    getch();
    clear();
}
