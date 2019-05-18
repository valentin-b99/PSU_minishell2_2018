/*
** EPITECH PROJECT, 2019
** manage_list
** File description:
** manage_list
*/

#include "../include/minishell.h"

void init_list(list_t *list)
{
    list->nb = 0;
    list->first = NULL;
}

void add_elem(list_t *list, char *name, char *value)
{
    elem_t *elem = malloc(sizeof(*elem));

    if ((elem->name = malloc(sizeof(char) * (my_strlen(name) + 1))) == NULL)
        exit(84);
    if ((elem->value = malloc(sizeof(char) * (my_strlen(value) + 1))) == NULL)
        exit(84);
    mem_set(&elem->name, my_strlen(name) + 1);
    mem_set(&elem->value, my_strlen(value) + 1);
    for (int i = 0; i < my_strlen(name); i++)
        elem->name[i] = name[i];
    for (int i = 0; i < my_strlen(value); i++)
        elem->value[i] = value[i];
    elem->next = list->first;
    list->nb += 1;
    list->first = elem;
}

void rem_elem(list_t *list, char *name)
{
    elem_t *elem = list->first;
    elem_t *last_elem = list->first;

    while (elem) {
        if (!my_strcmp(elem->name, name)) {
            if (elem == list->first)
                list->first = elem->next;
            else
                last_elem->next = elem->next;
            free(elem->name);
            free(elem->value);
            free(elem);
            list->nb -= 1;
            return;
        }
        last_elem = elem;
        elem = elem->next;
    }
}

void edit_elem(list_t *list, char *name, char *value)
{
    elem_t *elem = list->first;

    while (elem) {
        if (!my_strcmp(elem->name, name)) {
            elem->value = malloc(sizeof(char) * (my_strlen(value) + 1));
            mem_set(&elem->value, my_strlen(value) + 1);
            for (int i = 0; i < my_strlen(value); i++)
                elem->value[i] = value[i];
            return;
        }
        elem = elem->next;
    }
}