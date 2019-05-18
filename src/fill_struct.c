/*
** EPITECH PROJECT, 2019
** fill_struct
** File description:
** fill_struct
*/

#include "../include/minishell.h"

int name_len(char *str)
{
    int i = 0;

    while (str[i] != CHR_BTW_NAME_VAL_DEF)
        i++;
    return (i);
}

char *return_name(char *str)
{
    char *dest;

    if ((dest = malloc(sizeof(char) * (name_len(str) + 1))) == NULL)
        exit(84);
    for (int i = 0; str[i] != CHR_BTW_NAME_VAL_DEF; i++)
        dest[i] = str[i];
    dest[name_len(str)] = 0;
    return (dest);
}

void fill_struct(list_t *list, char **env)
{
    init_list(list);
    for (int i = 0; i < str_array_len(env); i++)
        add_elem(list, return_name(env[i]), env[i] + name_len(env[i]) + 1);
}
