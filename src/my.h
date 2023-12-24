/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** eat
*/
#include <string.h>
#include <stdarg.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#ifndef B_PSU_100_LIL_1_1_SOKOBAN_HELENE_HOUPLAIN_MY_H
    #define B_PSU_100_LIL_1_1_SOKOBAN_HELENE_HOUPLAIN_MY_H
typedef struct {
    int new_x;
    int new_y;
} playerposition_t;

typedef struct {
    int i;
    int y;
} index1_t;

typedef struct {
    int nbr_rows;
    int nbr_col;
} size1_t;
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_nbr_uns(int nb);
int cond3(int i, const char *format, va_list list);
int cond2(int i, const char *format, va_list list);
int cond(int i, const char *format, va_list list);
int mini_printf(const char *format, ...);
int size_file(char const *filepath);
int count_col(char const *filepath);
int count_rows(char const *filepath);
char  **two(char const *filepath);
int display_two(char **det, int nbr_rows, int x, int y);
int helper(void);
playerposition_t find_player(char **det);
void find_player2(int i, char **det, playerposition_t *playerPos);
void sokoban(char **det, char **argv, size1_t size);
int move_player(int *x, int *y, int ch, char **det);
int move_up(playerposition_t position, int *x, int *y, char **det);
int move_down(playerposition_t position, int *x, int *y, char **det);
int move_left(playerposition_t position, int *x, int *y, char **det);
int move_right(playerposition_t position, int *x, int *y, char **det);
int win(char **argv, char **det);
int copy(char **copy_det, int i, int y, int count);
int copy2(char **copy_det, int i, int y, int count);
char **pass_on_zero(char **argv, char **det);
void pass_on_zero2(char **det, index1_t ind, char **copy_det);
void handle_sokoban(char **det, char **argv, playerposition_t playerPos,
    size1_t size);
int is_loose(char **argv, char **det);
int is_loose2(char **det, index1_t ind, int count);
int is_loose(char **argv, char **det);
int error(char **argv, size1_t size);
int is_regular_file(const char *path);
int not_valid_file2(index1_t ind, char **det);
int not_valid_file(char **det, char **argv);
int loose_condition(int count);
int get_int(char **det, index1_t *ind, int count);
#endif //B_PSU_100_LIL_1_1_SOKOBAN_HELENE_HOUPLAIN_MY_H
