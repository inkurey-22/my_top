/*
** EPITECH PROJECT, 2024
** base
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>

#include <curses.h>

#include "my_printf.h"

#include "my_top.h"

void check_inputs(coords_t *coords)
{
    int ch = getch();

    if (ch == 'q'){
        endwin();
        exit(0);
    }
    if (ch == KEY_UP)
        coords->x--;
    if (ch == KEY_DOWN)
        coords->x++;
    if (ch == KEY_LEFT)
        coords->y--;
    if (ch == KEY_RIGHT)
        coords->y++;
}

void launch_top(void)
{
    coords_t coords = {0, 0};

    while (1) {
        print_header();
        check_inputs(&coords);
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
