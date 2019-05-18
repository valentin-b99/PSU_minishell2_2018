/*
** EPITECH PROJECT, 2019
** unsetenv
** File description:
** unsetenv
*/

#include "../include/minishell.h"

void unset_env(char **arr_inputs, char ***env, list_t *l_env)
{
    if (str_array_len(arr_inputs) < 2) {
        my_putstr(arr_inputs[0]);
        my_putstr(ERR_UNSETENV);
    } else {
        for (int i = 1; i < str_array_len(arr_inputs); i++)
            rem_elem(l_env, arr_inputs[i]);
        set_list_to_env(l_env, env);
    }
}