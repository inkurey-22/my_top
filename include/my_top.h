/*
** EPITECH PROJECT, 2024
** bsmytop
** File description:
** my_top
*/
#ifndef MY_TOP_H_
    #define MY_TOP_H_

typedef struct coords_s {
    int x;
    int y;
} coords_t;

int my_getloadavg(double loadavg[], int nelem);

#endif /* !MY_TOP_H_ */
