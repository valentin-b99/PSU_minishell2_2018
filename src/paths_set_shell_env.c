/*
** EPITECH PROJECT, 2019
** paths_set_shell_env
** File description:
** paths_set_sell_env
*/

#include "../include/minishell.h"

char **get_paths(char **env)
{
    int i = 0;

    while (my_strncmp(env[i], "PATH=", 4) != 0)
        i++;
    return (my_str_to_word_array(env[i] + 5, ":\n"));
}

void set_shell_env(list_t *l_env, char ***env, char *fname)
{
    char *buff;

    if ((buff = malloc(sizeof(char) * 500)) == NULL)
        exit(84);
    mem_set(&buff, 500);
    getcwd(buff, 500);
    edit_elem(l_env, VAR_SHELL, my_strcat(buff, fname));
    set_list_to_env(l_env, env);
    free(buff);
}