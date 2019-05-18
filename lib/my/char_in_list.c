/*
** EPITECH PROJECT, 2019
** char_in_list
** File description:
** char_in_list
*/

#include "../../include/my.h"

int char_in_list(char c, char *list_char)
{
    for (int i = 0; list_char[i]; i++)
        if (list_char[i] == c)
            return (1);
    return (0);
}