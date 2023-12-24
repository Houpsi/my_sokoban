/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** handle message error
*/
#include "my.h"

int error(char **argv, size1_t size)
{
    int terminal_rows;
    int terminal_cols;

    getmaxyx(stdscr, terminal_rows, terminal_cols);
    clear();
    if (terminal_rows < size.nbr_rows || terminal_cols < size.nbr_col) {
        clear();
        printw("enlarge the terminal");
        refresh();
        return 1;
    }
    return 0;
}

int is_regular_file(const char *path)
{
    struct stat path_stat;

    if (stat(path, &path_stat) != 0)
        return 0;
    return S_ISREG(path_stat.st_mode);
}

int not_valid_file2(index1_t ind, char **det)
{
    if (det[ind.i][ind.y] != '#' && det[ind.i][ind.y] != 'O' &&
    det[ind.i][ind.y] != 'X' && det[ind.i][ind.y] != 'P' &&
    det[ind.i][ind.y] != ' ' && det[ind.i][ind.y] != '\n' &&
    det[ind.i][ind.y] != '\0')
        exit(84);
}

int not_valid_file(char **det, char **argv)
{
    index1_t ind;
    int nbr_rows = count_rows(argv[1]) + 1;
    int nbr_col = count_col(argv[1]) + 1;

    for (ind.i = 0; ind.i < nbr_rows; ind.i++) {
        for (ind.y = 0; ind.y < nbr_col; ind.y++) {
            not_valid_file2(ind, det);
        }
    }
}

int get_int(char **det, index1_t *ind, int count)
{
    if (det[(*ind).i][(*ind).y] == 'X' &&
        (det[(*ind).i][(*ind).y + 1] == '#' &&
        det[(*ind).i - 1][(*ind).y] == '#')) {
        count = loose_condition(count);
    }
    return count;
}
