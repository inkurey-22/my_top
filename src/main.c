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

int main(void)
{
    double loadavg[3];
    coords_t coords = {0, 0};

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    timeout(1000);
    while (1) {
        if (my_getloadavg(loadavg, 3) == -1){
            endwin();
            return 84;
        }
        mvprintw(coords.x, coords.y, "Load average: %.2f %.2f %.2f\n",
            loadavg[0], loadavg[1], loadavg[2]);
        check_inputs(&coords);
        clear();
    }
    endwin();
    return 0;
}
