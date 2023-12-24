/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** end : win or not
*/
#include "my.h"

int copy(char **copy_det, int i, int y, int count)
{
    if (copy_det[i][y] == 'O')
        count++;
    return count;
}

int compare(char **det, char **copy_det, index1_t ind, int count)
{
    if (det[ind.i][ind.y] == 'X' && copy_det[ind.i][ind.y] == 'O') {
        count--;
        if (count <= 0) {
            endwin();
            exit(0);
        }
    }
    return count;
}

int win(char **argv, char **det)
{
    index1_t ind;
    int nbr_rows = count_rows(argv[1]) + 1;
    int nbr_col = count_col(argv[1]);
    char **copy_det = two(argv[1]);
    int count = 0;

    for (int i = 0; i < nbr_rows; i++) {
        for (int y = 0; y < (nbr_col + 1); y++)
            count = copy(copy_det, i, y, count);
    }
    for (ind.i = 0; ind.i < nbr_rows; ind.i++) {
        for (ind.y = 0; ind.y < (nbr_col + 1); ind.y++) {
            count = compare(det, copy_det, ind, count);
        }
    }
}

void pass_on_zero2(char **det, index1_t ind, char **copy_det)
{
    if (copy_det[ind.i][ind.y] == 'O' && det[ind.i][ind.y] == ' ')
        det[ind.i][ind.y] = 'O';
}

char **pass_on_zero(char **argv, char **det)
{
    index1_t ind;
    char **copy_det = two(argv[1]);
    int nbr_rows = count_rows(argv[1]) + 1;
    int nbr_col = count_col(argv[1]);

    for (ind.i = 0; ind.i < nbr_rows; ind.i++) {
        for (ind.y = 0; ind.y < (nbr_col + 1); ind.y++) {
            pass_on_zero2(det, ind, copy_det);
        }
    }
    return det;
}
