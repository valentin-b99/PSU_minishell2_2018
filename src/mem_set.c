/*
** EPITECH PROJECT, 2019
** mem_set
** File description:
** mem_set
*/

#include "../include/minishell.h"

void mem_set(char **str, int len)
{
    for (int i = 0; i < len; i++)
        (*str)[i] = 0;
}