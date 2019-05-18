/*
** EPITECH PROJECT, 2019
** read_inputs.c
** File description:
** read_inputs
*/

#include "../include/minishell.h"

int prompt_getline(list_t *l_env, char **input, exit_t *exit_val)
{
    size_t len = 0;

    prompt(l_env);
    if (getline(input, &len, stdin) == -1) {
        exit_val->value = 0;
        exit_val->display = 1;
        return (1);
    }
    return (0);
}

void exec_cmds2(char *input, char ***env, list_t *l_env, char ***arr_paths)
{
    char **arr_inputs;
    pipe_f_t *pipe_f = malloc(sizeof(pipe_f_t));

    epur_str(&input);
    arr_inputs = my_str_to_word_array(input, "|");
    if (verrif_input_after_pipe(input, arr_inputs)) {
        my_putstr(ERR_INV_NULL_CMD);
        return;
    }
    pipe_f->arr_inputs = arr_inputs;
    pipe_f->env = env;
    pipe_f->l_env = l_env;
    pipe_f->arr_paths = arr_paths;
    pipe_function(pipe_f);
    free(arr_inputs);
    free(pipe_f);
}

void exec_cmds(char *input, char ***env, list_t *l_env, char ***arr_paths)
{
    char **arr_inputs;
    int save_out = dup(1);
    int right_state_redirect = 0;

    epur_str(&input);
    if (redirections(input, &arr_inputs))
        return;
    exec_cmds2(arr_inputs[0], env, l_env, arr_paths);
    dup2(save_out, 1);
    close(save_out);
    free(arr_inputs);
}

int read_input(char ***env, list_t *l_env, char ***arr_paths,
exit_t *exit_val)
{
    char *input;
    char **arr_inputs;

    if ((input = malloc(sizeof(char) * 500)) == NULL)
        exit (84);
    if (prompt_getline(l_env, &input, exit_val))
        return (0);
    arr_inputs = my_str_to_word_array(input, ";\n");
    for (int i = 0; arr_inputs[i]; i++) {
        cmd_exit(arr_inputs[i], exit_val);
        exec_cmds(arr_inputs[i], env, l_env, arr_paths);
    }
    free(arr_inputs);
    free(input);
    if (exit_val->value > -1)
        return (0);
    return (1);
}