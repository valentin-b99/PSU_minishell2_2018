/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    char *res = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    int dest_len = my_strlen(dest);

    for (int i = 0; dest[i]; i++)
        res[i] = dest[i];
    for (int i = 0; src[i]; i++)
        res[dest_len + i] = src[i];
    res[dest_len + my_strlen(src)] = 0;
    return (res);
}
