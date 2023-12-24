/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** loose
*/
#include "my.h"

int copy2(char **copy_det, int i, int y, int count)
{
    if (copy_det[i][y] == 'X')
        count++;
    return count;
}

int loose_condition(int count)
{
    if (count <= 0) {
        endwin();
        exit(1);
    }
    count --;
    return count;
}

int is_loose2(char **det, index1_t ind, int count)
{
    if (det[ind.i][ind.y] == 'X' &&
        (det[ind.i + 1][ind.y] == '#' && det[ind.i][ind.y + 1] == '#')) {
        count = loose_condition(count);
        return count;
    }
    if (det[ind.i][ind.y] == 'X' &&
        (det[ind.i][ind.y - 1] == '#' && det[ind.i + 1][ind.y] == '#')) {
        count = loose_condition(count);
        return count;
    }
    if (det[ind.i][ind.y] == 'X' &&
        (det[ind.i - 1][ind.y] == '#' && det[ind.i][ind.y - 1] == '#')) {
        count = loose_condition(count);
        return count;
    }
    count = get_int(det, &ind, count);
    return count;
}

int is_loose(char **argv, char **det)
{
    index1_t ind;
    int nbr_rows = count_rows(argv[1]) + 1;
    int nbr_col = count_col(argv[1]) + 1;
    char **copy_det = two(argv[1]);
    int count = 0;

    for (int i = 0; i < nbr_rows; i++) {
        for (int y = 0; y < nbr_col; y++)
            count = copy2(copy_det, i, y, count);
    }
    for (ind.i = 0; ind.i < nbr_rows; ind.i++) {
        for (ind.y = 0; ind.y < nbr_col; ind.y++) {
            count = is_loose2(det, ind, count);
        }
    }
    loose_condition(count);
    return 0;
}
