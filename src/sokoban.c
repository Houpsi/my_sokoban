/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** sokoban
*/
#include "my.h"

void find_player2(int i, char **det, playerposition_t *playerPos)
{
    for (int j = 0; det[i][j] != '\0'; j++)
        if (det[i][j] == 'P') {
            playerPos->new_x = i;
            playerPos->new_y = j;
            return;
        }
}

playerposition_t find_player(char **det)
{
    playerposition_t playerPos = {-1, -1 };

    for (int i = 0; det[i] != 0; i++) {
        find_player2(i, det, &playerPos);
    }
    if (playerPos.new_x == -1 || playerPos.new_y == -1)
        exit(84);
    return playerPos;
}

static void move_display_refresh(int new_x, int new_y, char **det,
    int nbr_rows)
{
    move(new_x, new_y);
    display_two(det, nbr_rows, new_x, new_y);
    refresh();
}

static int intermediate(char **argv, char **det)
{
    win(argv, det);
    is_loose(argv, det);
}

void handle_sokoban(char **det, char **argv, playerposition_t playerPos,
    size1_t size)
{
    int ch = 0;
    char **copy_det = two(argv[1]);

    initscr();
    keypad(stdscr, TRUE);
    move_display_refresh(playerPos.new_x, playerPos.new_y, det, size.nbr_rows);
    while (ch != 'Q') {
        clear();
        if (error(argv, size))
            continue;
        display_two(det, size.nbr_rows, playerPos.new_x, playerPos.new_y);
        intermediate(argv, det);
        ch = getch();
        if (ch == ' ')
            sokoban(copy_det, argv, size);
        move_player(&(playerPos.new_x), &(playerPos.new_y), ch, det);
        move(playerPos.new_x, playerPos.new_y);
        det = pass_on_zero(argv, det);
    }
    endwin();
}

void sokoban(char **det, char **argv, size1_t size)
{
    playerposition_t playerPosition = find_player(det);
    int nbr_rows = count_rows(argv[1]) + 1;

    handle_sokoban(det, argv, playerPosition, size);
}

int main(int argc, char **argv)
{
    char **det;
    size1_t size;

    if (argc != 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        helper();
        return 0;
    }
    if (!is_regular_file(argv[1]))
        return 84;
    det = two(argv[1]);
    if (det == NULL)
        return 84;
    not_valid_file(det, argv);
    size.nbr_rows = count_rows(argv[1]) + 1;
    size.nbr_col = count_col(argv[1]);
    sokoban(det, argv, size);
}
