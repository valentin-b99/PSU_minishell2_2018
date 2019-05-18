/*
** EPITECH PROJECT, 2019
** cmd_exit
** File description:
** cmd_exit
*/

#include "../include/minishell.h"

void cmd_exit_next(char **arr_inputs, exit_t *exit_val)
{
    if (str_array_len(arr_inputs) < 3 && my_str_isnum(arr_inputs[1])) {
        exit_val->value = my_getnbr(arr_inputs[1]);
    } else {
        my_puterror(arr_inputs[0]);
        my_puterror(ERR_EXPR_SYNTAX);
    }
}

void cmd_exit(char *input, exit_t *exit_val)
{
    char **arr_inputs;

    epur_str(&input);
    arr_inputs = my_str_to_word_array(input, " \n");
    if (!my_strcmp(arr_inputs[0], CMD_EXIT)) {
        if (str_array_len(arr_inputs) > 1) {
            cmd_exit_next(arr_inputs, exit_val);
        } else {
            exit_val->value = 0;
        }
        if (isatty(0))
            exit_val->display = 1;
    }
}