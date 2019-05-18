/*
** EPITECH PROJECT, 2019
** prompt
** File description:
** prompt
*/

#include "../include/minishell.h"

void my_putinv(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        write(0, &str[i], 1);
}

void prompt(list_t *l_env)
{
    my_putinv("[");
    my_putinv(return_user(l_env));
    my_putinv("@");
    my_putinv(return_host(l_env));
    my_putinv(" ");
    my_putinv(return_current_folder(l_env));
    my_putinv("]$ ");
}
