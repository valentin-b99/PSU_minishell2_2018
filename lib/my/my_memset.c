/*
** EPITECH PROJECT, 2019
** my_memset
** File description:
** my_memset
*/

#include "../../include/my.h"

void my_memset(char **str, char c, int len)
{
    for (int i = 0; i < len; i++)
        (*str)[i] = c;
}