/*
** EPITECH PROJECT, 2019
** str_array_len
** File description:
** str_array_len
*/

#include "../include/minishell.h"

int str_array_len(char **arr)
{
    int nb = 0;

    while (arr[nb])
        nb++;
    return (nb);
}