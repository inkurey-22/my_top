/*
** EPITECH PROJECT, 2024
** base
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>

#include "my_printf.h"

#include "my_top.h"

void check_inputs(void)
{
    const int ch = getch();

    if (ch == 'q'){
        endwin();
        exit(0);
    }
}

void launch_top(void)
{
    while (1) {
        print_header();
        check_inputs();
        clear();
    }
}

int main(void)
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    timeout(3000);
    launch_top();
    endwin();
    return 0;
}
