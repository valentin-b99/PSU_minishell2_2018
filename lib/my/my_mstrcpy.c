/*
** EPITECH PROJECT, 2018
** my_mstrcpy
** File description:
** my_mstrcpy
*/

#include <stdlib.h>
#include "../../include/my.h"

int my_mstrcpy(char **dest, char *src)
{
    int i = 0;

    if ((*dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
        return (1);
    my_memset(dest, 0, my_strlen(src) + 1);
    while (src[i]) {
        (*dest)[i] = src[i];
        i++;
    }
    (*dest)[i] = 0;
    return (0);
}