/*
** EPITECH PROJECT, 2019
** my_puterror
** File description:
** my_puterror
*/

#include <unistd.h>

void my_puterror(char const *str)
{
    for (int i = 0; str[i]; i++)
        write(2, &str[i], 1);
}
