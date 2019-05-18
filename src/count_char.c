/*
** EPITECH PROJECT, 2019
** count_char.c
** File description:
** count_char
*/

#include "../include/minishell.h"

int count_char(char *str, char c)
{
    int nb = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            nb++;
    return (nb);
}