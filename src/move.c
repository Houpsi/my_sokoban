/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** move of the player
*/
#include "my.h"

int move_up(playerposition_t position, int *x, int *y, char **det)
{
    position.new_x -= 1;
    if (det[position.new_x][position.new_y] != '#' &&
        det[position.new_x][position.new_y] != 'X' && position.new_x != 0) {
        *x = position.new_x;
        *y = position.new_y;
        det[*(x)][*(y)] = ' ';
        det[position.new_x][position.new_y] = 'P';
        det[position.new_x + 1][position.new_y] = ' ';
    }
    if (det[position.new_x][position.new_y] == 'X' &&
        det[position.new_x - 1][position.new_y] != '#' &&
        det[position.new_x - 1][position.new_y] != 'X' &&
        position.new_x != 0) {
        *x = position.new_x;
        *y = position.new_y;
        det[position.new_x][position.new_y] = ' ';
        det[position.new_x - 1][position.new_y] = 'X';
        det[position.new_x][position.new_y] = 'P';
        det[position.new_x + 1][position.new_y] = ' ';
    }
}

int move_down(playerposition_t position, int *x, int *y, char **det)
{
    position.new_x += 1;
    if (det[position.new_x][position.new_y] != '#' &&
        det[position.new_x][position.new_y] != 'X') {
        *x = position.new_x;
        *y = position.new_y;
        det[*(x)][*(y)] = ' ';
        det[position.new_x][position.new_y] = 'P';
        det[position.new_x - 1][position.new_y] = ' ';
    }
    if (det[position.new_x][position.new_y] == 'X' &&
        det[position.new_x + 1][position.new_y] != '#' &&
        det[position.new_x + 1][position.new_y] != 'X'){
        *x = position.new_x;
        *y = position.new_y;
        det[position.new_x][position.new_y] = ' ';
        det[position.new_x + 1][position.new_y] = 'X';
        det[position.new_x][position.new_y] = 'P';
        det[position.new_x - 1][position.new_y] = ' ';
    }
}

int move_left(playerposition_t position, int *x, int *y, char **det)
{
    position.new_y -= 1;
    if (det[position.new_x][position.new_y] != '#' &&
        det[position.new_x][position.new_y] != 'X' && position.new_y != 0) {
        *x = position.new_x;
        *y = position.new_y;
        det[*(x)][*(y)] = ' ';
        det[position.new_x][position.new_y] = 'P';
        det[position.new_x][position.new_y + 1] = ' ';
    }
    if (det[position.new_x][position.new_y] == 'X' &&
            det[position.new_x][position.new_y - 1] != '#' &&
            det[position.new_x][position.new_y - 1] != 'X' &&
            position.new_y != 0) {
        *x = position.new_x;
        *y = position.new_y;
        det[position.new_x][position.new_y] = ' ';
        det[position.new_x][position.new_y - 1] = 'X';
        det[position.new_x][position.new_y] = 'P';
        det[position.new_x][position.new_y + 1] = ' ';
    }
}

int move_right(playerposition_t position, int *x, int *y, char **det)
{
    position.new_y += 1;
    if (det[position.new_x][position.new_y] != '#' &&
        det[position.new_x][position.new_y] != 'X') {
        *x = position.new_x;
        *y = position.new_y;
        det[*(x)][*(y)] = ' ';
        det[position.new_x][position.new_y] = 'P';
        det[position.new_x][position.new_y - 1] = ' ';
    }
    if (det[position.new_x][position.new_y] == 'X' &&
            det[position.new_x][position.new_y + 1] != '#' &&
            det[position.new_x][position.new_y + 1] != 'X') {
        *x = position.new_x;
        *y = position.new_y;
        det[position.new_x][position.new_y] = ' ';
        det[position.new_x][position.new_y + 1] = 'X';
        det[position.new_x][position.new_y] = 'P';
        det[position.new_x][position.new_y - 1] = ' ';
    }
}

int move_player(int *x, int *y, int ch, char **det)
{
    playerposition_t position;

    position.new_x = *x;
    position.new_y = *y;
    switch (ch) {
        case KEY_UP:
            move_up(position, x, y, det);
            break;
        case KEY_DOWN:
            move_down(position, x, y, det);
            break;
        case KEY_LEFT:
            move_left(position, x, y, det);
            break;
        case KEY_RIGHT:
            move_right(position, x, y, det);
            break;
    }
}
