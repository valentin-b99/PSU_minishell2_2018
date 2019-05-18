/*
** EPITECH PROJECT, 2019
** epur_str
** File description:
** epur_str
*/

#include "../include/minishell.h"

int check_spaces_before(char *str)
{
    int i = 0;

    while (str[i] && (str[i] < 33 || str[i] > 126))
        i++;
    return (i);
}

void epur_str(char **str)
{
    char *str_cpy;
    int b_spaces = check_spaces_before(*str);
    int i_str = 0;

    if ((str_cpy = malloc(sizeof(char) * (my_strlen(*str) + 1))) == NULL)
        exit(84);
    mem_set(&str_cpy, my_strlen(*str));
    str_cpy = my_strcpy(str_cpy, *str);
    mem_set(str, my_strlen(str_cpy));
    for (int i_scpy = 0; str_cpy[i_scpy]; i_scpy++) {
        if (str_cpy[i_scpy] > 32 && str_cpy[i_scpy] < 127) {
            (*str)[i_str] = str_cpy[i_scpy];
            i_str++;
        } else if (i_scpy > b_spaces &&
            str_cpy[i_scpy + 1] > 32 && str_cpy[i_scpy + 1] < 127) {
            (*str)[i_str] = ' ';
            i_str++;
        }
    }
    (*str)[i_str] = 0;
    free(str_cpy);
}