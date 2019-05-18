/*
** EPITECH PROJECT, 2019
** redirection.c
** File description:
** redirections
*/

#include "../include/minishell.h"

void exec_one_right_redirect(char *file_name)
{
    int fd = -1;

    epur_str(&file_name);
    if ((fd = open(file_name, O_CREAT|O_WRONLY|O_TRUNC,
        S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)) == -1)
        exit(84);
    dup2(fd, 1);
    close(fd);
}

void exec_two_right_redirect(char *file_name)
{
    int fd = -1;

    epur_str(&file_name);
    if ((fd = open(file_name, O_CREAT|O_WRONLY|O_APPEND,
        S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)) == -1)
        exit(84);
    dup2(fd, 1);
    close(fd);
}

int redirections(char *input, char ***arr_inputs)
{
    *arr_inputs = my_str_to_word_array_v2(input, ">");
    if (char_is_in_str(input, ">") && str_array_len(*arr_inputs) != 2) {
        *arr_inputs = my_str_to_word_array_v2(input, ">>");
        if (str_array_len(*arr_inputs) != 2 ||
            ((*arr_inputs)[1] && char_is_in_str((*arr_inputs)[1], "><|"))) {
            my_putstr(ERR_AMB_OUT_REDIRECT);
            return (1);
        }
        exec_two_right_redirect((*arr_inputs)[1]);
    } else if ((*arr_inputs)[1] && char_is_in_str((*arr_inputs)[1], "><|")) {
        my_putstr(ERR_AMB_OUT_REDIRECT);
        return (1);
    } else {
        if ((*arr_inputs)[1])
            exec_one_right_redirect((*arr_inputs)[1]);
    }
    return (0);
}