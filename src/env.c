/*
** EPITECH PROJECT, 2019
** env
** File description:
** env
*/

#include "../include/minishell.h"

void display_env(char ***env)
{
    for (int i = 0; i < str_array_len(*env); i++) {
        my_putstr((*env)[i]);
        my_putstr("\n");
    }
}

int env_name_exist(list_t *list, char *name)
{
    elem_t *elem = list->first;

    while (elem) {
        if (!my_strcmp(elem->name, name))
            return (1);
        elem = elem->next;
    }
    return (0);
}