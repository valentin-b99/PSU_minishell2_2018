/*
** EPITECH PROJECT, 2019
** cmd_cd
** File description:
** cmd_cd
*/

#include "../include/minishell.h"

int cd_home(list_t *l_env)
{
    elem_t *elem = l_env->first;

    while (elem) {
        if (!my_strcmp(elem->name, VAR_HOME)) {
            chdir(elem->value);
            return (1);
        }
        elem = elem->next;
    }
    return (0);
}

int cd_rev(list_t *l_env, char ***env, char **old_pwd)
{
    size_t size;
    char *buff;

    if ((buff = malloc(sizeof(char) * 300)) == NULL)
        exit(84);
    mem_set(&buff, 300);
    getcwd(buff, 300);
    chdir(*old_pwd);
    edit_elem(l_env, VAR_OLDPWD, buff);
    my_mstrcpy(old_pwd, buff);
    free(buff);
    return (1);
}

void cmd_cd_next(char **arr_inputs, list_t *l_env, char ***env, char **old_pwd)
{
    char *buff;
    int state = 0;

    if ((buff = malloc(sizeof(char) * 300)) == NULL)
        exit(84);
    mem_set(&buff, 300);
    if (!my_strcmp(arr_inputs[1], CMD_CD_REV))
        state = cd_rev(l_env, env, old_pwd);
    if (!state && !access(arr_inputs[1], R_OK)) {
        getcwd(buff, 300);
        edit_elem(l_env, VAR_OLDPWD, buff);
        my_mstrcpy(old_pwd, buff);
    }
    if (!my_strcmp(arr_inputs[1], CMD_CD_HOME_1) ||
        !my_strcmp(arr_inputs[1], CMD_CD_HOME_2))
        state = cd_home(l_env);
    if (state)
        my_mstrcpy(old_pwd, buff);
    if (!state && chdir(arr_inputs[1]))
        print_error(arr_inputs[1], errno);
    free(buff);
}

void cmd_cd_a(char *buff, char **old_pwd, list_t *l_env)
{
    getcwd(buff, 300);
    my_mstrcpy(old_pwd, buff);
    edit_elem(l_env, VAR_OLDPWD, buff);
    cd_home(l_env);
}

void cmd_cd(char **arr_inputs, list_t *l_env, char ***env)
{
    size_t size;
    char *buff;
    static char *old_pwd;

    if (str_array_len(arr_inputs) > 2) {
        my_putstr(arr_inputs[0]);
        my_puterror(ERR_TO_MANY_ARGS);
        return;
    }
    if ((buff = malloc(sizeof(char) * 300)) == NULL)
        exit(84);
    mem_set(&buff, 300);
    if (str_array_len(arr_inputs) < 2)
        cmd_cd_a(buff, &old_pwd, l_env);
    else
        cmd_cd_next(arr_inputs, l_env, env, &old_pwd);
    mem_set(&buff, 300);
    getcwd(buff, 300);
    edit_elem(l_env, VAR_PWD, buff);
    set_list_to_env(l_env, env);
    free(buff);
}