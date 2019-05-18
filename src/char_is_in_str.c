/*
** EPITECH PROJECT, 2019
** char_is_in_str.c
** File description:
** char_is_in_str
*/

#include "../include/minishell.h"

int char_is_in_str(char *str, char *list_str)
{
    for (int i = 0; str[i]; i++)
        if (char_in_list(str[i], list_str))
            return (1);
    return (0);
}