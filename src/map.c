/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** check map
*/
#include "my.h"

int size_file(char const *filepath)
{
    struct stat sb;

    stat(filepath, &sb);
    return (sb.st_size);
}

int count_rows(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = size_file(filepath);
    char *buffer = malloc((sizeof(char) * size + 1));
    long int read_file = read(fd, buffer, size);
    int count = 0;

    for (int i = 0; buffer[i] != 0; i++)
        if (buffer[i] == '\n')
            count++;
    free(buffer);
    return count;
}

int count_col(char const *filepath)
{
    int nbr = 0;
    int fd = open(filepath, O_RDONLY);
    int size = size_file(filepath);
    char *buffer = malloc((sizeof(char) * size + 1));
    int read_file = read(fd, buffer, size);
    int a = 0;

    while (buffer[a] != '\n') {
        nbr ++;
        a++;
    }
    close(fd);
    return nbr;
}

static int count_col2(char const *buffer, int a)
{
    int nbr = 0;

    while (buffer[a] != '\n' && buffer[a] != '\0') {
        nbr++;
        a++;
    }
    return nbr;
}

char  **two(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = size_file(filepath);
    char *buffer = malloc((sizeof(char) * size + 1));
    long int read_file = read(fd, buffer, size);
    int nbr_rows = count_rows(filepath) + 1;
    char **det = malloc(sizeof(char *) * (nbr_rows + 1));
    int y;
    int a = 0;
    int nbr_col;

    for (int i = 0; i < nbr_rows; i++) {
        nbr_col = count_col2(buffer, a);
        det[i] = malloc(sizeof(char) * (nbr_col + 1));
        for (y = 0; y < nbr_col + 1; y++) {
            det[i][y] = buffer[a];
            a++;
        }
        det[i][y] = '\0';
    }
    det[nbr_rows] = 0;
    return det;
}

int display_two(char **det, int nbr_rows, int x, int y)
{
    for (int i = 0; i != nbr_rows; i++)
        printw("%s", det[i]);
    move(x, y);
    refresh();
}
