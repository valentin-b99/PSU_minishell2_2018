/*
** EPITECH PROJECT, 2019
** cmds
** File description:
** cmds
*/

#include "../include/minishell.h"

int cmd_is_valid(char *cmd)
{
    if (!my_strcmp(cmd, ""))
        return (0);
    if (!my_strcmp(cmd, CMD_EXIT))
        return (0);
    if (!my_strcmp(cmd, CMD_ENV))
        return (0);
    if (!my_strcmp(cmd, CMD_SETENV))
        return (0);
    if (!my_strcmp(cmd, CMD_UNSETENV))
        return (0);
    if (!my_strcmp(cmd, CMD_CD))
        return (0);
    return (1);
}

int search_valid_path(char ***arr_paths, char *cmd)
{
    for (int i = 0; i < str_array_len(*arr_paths); i++)
        if (!access(my_strcat(my_strcat((*arr_paths)[i], "/"), cmd), X_OK))
            return (i);
    if (!access(cmd, X_OK))
        return (-1);
    if (access(cmd, F_OK)) {
        my_puterror(cmd);
        my_puterror(ERR_CMDNFOUND);
    } else if (!access(cmd, F_OK)) {
        print_error(cmd, 13);
    } else {
        print_error(cmd, errno);
    }
    return (-84);
}

void other_cmds(char ***arr_inputs, char ***arr_paths, char ***env)
{
    int col_path;
    int status;

    if (cmd_is_valid((*arr_inputs)[0])) {
        if ((col_path = search_valid_path(arr_paths, (*arr_inputs)[0])) == -84)
            return;
        if (col_path == -1 && (status = fork()) == 0) {
            execve((*arr_inputs)[0], *arr_inputs, *env);
            print_error((*arr_inputs)[0], errno);
            exit(status / 256);
        } else if (col_path > -1 && (status = fork()) == 0) {
            execve(my_strcat(my_strcat((*arr_paths)[col_path], "/"),
            (*arr_inputs)[0]), *arr_inputs, *env);
            print_error((*arr_inputs)[0], errno);
            exit(status / 256);
        }
        wait(&status);
        print_segflt_floatex(status);
    }
}

void my_cmds(char ***arr_inputs, char ***arr_paths, char ***env, list_t *l_env)
{
    if (!my_strcmp((*arr_inputs)[0], CMD_ENV))
        display_env(env);
    if (!my_strcmp((*arr_inputs)[0], CMD_SETENV))
        set_env(*arr_inputs, env, l_env);
    if (!my_strcmp((*arr_inputs)[0], CMD_UNSETENV))
        unset_env(*arr_inputs, env, l_env);
    if (!my_strcmp((*arr_inputs)[0], CMD_CD))
        cmd_cd(*arr_inputs, l_env, env);
}