/*
** EPITECH PROJECT, 2019
** pipe
** File description:
** pipe
*/

#include "../include/minishell.h"

int verrif_input_after_pipe(char *input, char **arr_input)
{
    if (count_char(input, '|') + 1 != str_array_len(arr_input))
        return (1);
    return (0);
}

void pipe_cmd(pipe_f_t *pipe_f, int i)
{
    char **array;
    int pfd[2];

    if (pipe(pfd))
        exit(84);
    if ((pipe_f->pid = fork()) == 0) {
        dup2(pfd[1], 1);
        close(pfd[0]);
        array = my_str_to_word_array(pipe_f->arr_inputs[i], " \n");
        my_cmds(&array, pipe_f->arr_paths, pipe_f->env, pipe_f->l_env);
        other_cmds(&array, pipe_f->arr_paths, pipe_f->env);
        exit(0);
    }
    dup2(pfd[0], 0);
    close(pfd[1]);
}

void pipe_cmd_end(pipe_f_t *pipe_f, int i)
{
    char **array;

    array = my_str_to_word_array(pipe_f->arr_inputs[i], " \n");
    my_cmds(&array, pipe_f->arr_paths, pipe_f->env, pipe_f->l_env);
    other_cmds(&array, pipe_f->arr_paths, pipe_f->env);
}

void pipe_function(pipe_f_t *pipe_f)
{
    int status;
    int i = 0;
    int save_in = dup(0);
    int save_out = dup(1);

    while (i < str_array_len(pipe_f->arr_inputs) - 1) {
        pipe_cmd(pipe_f, i);
        i++;
    }
    if (str_array_len(pipe_f->arr_inputs) < 2 ||
        !waitpid(pipe_f->pid, &status, WNOHANG))
        pipe_cmd_end(pipe_f, i);
    dup2(save_out, 1);
    close(save_out);
    dup2(save_in, 0);
    close(save_in);
}