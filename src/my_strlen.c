/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** zejh
*/
#include "my.h"

int my_strlen(char const *str)
{
    char h = 0;

    while (str[h] != '\0') {
        h ++;
    }
    return h;
}
