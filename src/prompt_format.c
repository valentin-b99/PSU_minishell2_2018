/*
** EPITECH PROJECT, 2019
** prompt_format
** File description:
** prompt_format
*/

#include "../include/minishell.h"

char *return_user(list_t *list)
{
    elem_t *elem = list->first;

    while (elem) {
        if (!my_strcmp(elem->name, VAR_USER))
            return (elem->value);
        elem = elem->next;
    }
    return ("");
}

char *parse_host(char *str)
{
    int i = 0;

    while (str[i] && str[i] != '.')
        i++;
    str[i] = 0;
    return (str);
}

char *return_host(list_t *list)
{
    elem_t *elem = list->first;
    char *host;

    while (elem) {
        if (!my_strcmp(elem->name, VAR_HOST))
            return (parse_host(elem->value));
        elem = elem->next;
    }
    return ("");
}

char *return_current_folder_next(list_t *list, elem_t *elem)
{
    int last_slash = 0;

    for (int i = 0; elem->value[i]; i++)
        if (elem->value[i] == '/')
            last_slash = i;
    if (!my_strcmp(elem->value + last_slash, "/"))
        return (elem->value + last_slash);
    else if (!my_strcmp(elem->value + last_slash + 1,
        return_user(list)))
        return ("~");
    return (elem->value + last_slash + 1);
}

char *return_current_folder(list_t *list)
{
    elem_t *elem = list->first;

    while (elem) {
        if (!my_strcmp(elem->name, VAR_PWD))
            return (return_current_folder_next(list, elem));
        elem = elem->next;
    }
    return ("");
}