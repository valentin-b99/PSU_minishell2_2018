/*
** EPITECH PROJECT, 2019
** setenv
** File description:
** setenv
*/

#include "../include/minishell.h"

void set_list_to_env(list_t *l_env, char ***env)
{
    elem_t *elem;
    int i = l_env->nb - 1;

    if (((*env) = malloc(sizeof(char *) * (l_env->nb + 1))) == NULL)
        exit(84);
    elem = l_env->first;
    while (elem) {
        if (((*env)[i] = malloc(sizeof(char) *
            (my_strlen(elem->name) + my_strlen(elem->value) + 2))) == NULL)
            exit(84);
        (*env)[i] = my_strcpy((*env)[i],
        my_strcat(my_strcat(elem->name, STR_BTW_NAME_VAL), elem->value));
        i--;
        elem = elem->next;
    }
    (*env)[l_env->nb] = NULL;
}

int str_name_is_valid(char *str)
{
    for (int i = 0; str[i]; i++)
        if ((str[i] < 48 || str[i] > 57) && (str[i] < 65 || str[i] > 90) &&
            (str[i] < 97 || str[i] > 122) && str[i] != 46 && str[i] != 95)
            return (0);
    return (1);
}

void made_set_env(char **arr_inputs, char ***env, list_t *l_env)
{
    if (env_name_exist(l_env, arr_inputs[1])) {
        edit_elem(l_env, arr_inputs[1], TEST_EDIT_ELEM);
        set_list_to_env(l_env, env);
    } else if (str_array_len(arr_inputs) == 2) {
        add_elem(l_env, arr_inputs[1], "");
        set_list_to_env(l_env, env);
    } else {
        add_elem(l_env, arr_inputs[1], arr_inputs[2]);
        set_list_to_env(l_env, env);
    }
}

void set_env(char **arr_inputs, char ***env, list_t *l_env)
{
    if (str_array_len(arr_inputs) < 2) {
        display_env(env);
    } else if (str_array_len(arr_inputs) > 3) {
        my_putstr(arr_inputs[0]);
        my_putstr(ERR_SETENV);
    } else {
        if (!my_charisalpha(arr_inputs[1][0])) {
            my_putstr(arr_inputs[0]);
            my_puterror(ERR_VAR_BEGIN_LETTER);
            return;
        }
        if (!str_name_is_valid(arr_inputs[1])) {
            my_putstr(arr_inputs[0]);
            my_puterror(ERR_VAR_ALPHA);
            return;
        }
        made_set_env(arr_inputs, env, l_env);
    }
}