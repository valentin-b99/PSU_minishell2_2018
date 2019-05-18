/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

#include "my.h"
#include "config.h"

#define TEST_EDIT_ELEM (str_array_len(arr_inputs) == 2) ? ("") : (arr_inputs[2])


typedef struct elem_s
{
    char *name;
    char *value;
    struct elem_s *next;
} elem_t;

typedef struct list_s
{
    int nb;
    struct elem_s *first;
} list_t;

typedef struct exit_s
{
    int display;
    int value;
} exit_t;

typedef struct pipe_f_s
{
    char **arr_inputs;
    char ***env;
    list_t *l_env;
    char ***arr_paths;
    pid_t pid;
} pipe_f_t;


/**
*? char_is_in_list.c
*/
int char_is_in_str(char *str, char *list_str);

/**
*? cmd_cd.c
*/
int cd_home(list_t *l_env);
int cd_rev(list_t *l_env, char ***env, char **old_pwd);
void cmd_cd(char **arr_inputs, list_t *l_env, char ***env);
void cmd_cd_next(char **arr_inputs, list_t *l_env, char ***env, char **old_pwd);

/**
*? cmd_exit.c
*/
void cmd_exit_next(char **arr_inputs, exit_t *exit_val);
void cmd_exit(char *input, exit_t *exit_val);

/**
*? cmds.c
*/
int cmd_is_valid(char *cmd);
int search_valid_path(char ***arr_paths, char *cmd);
void other_cmds(char ***arr_inputs, char ***arr_paths, char ***env);
void my_cmds(char ***arr_inputs, char ***arr_paths, char ***env, list_t *l_env);

/**
*? count_char.c
*/
int count_char(char *str, char c);

/**
*? env.c
*/
void display_env(char ***env);
int env_name_exist(list_t *list, char *name);

/**
*? epur_str.c
*/
int check_spaces_before(char *str);
void epur_str(char **str);

/**
*? fill_struct.c
*/
int name_len(char *str);
char *return_name(char *str);
void fill_struct(list_t *list, char **env);

/**
*? main.c
*/
exit_t init_exit_struct(void);
int after_read(exit_t exit_val);
void free_list(list_t *list);
int my_shell(char **env, char *fname);

/**
*? manage_list.c
*/
void init_list(list_t *list);
void add_elem(list_t *list, char *name, char *value);
void rem_elem(list_t *list, char *name);
void edit_elem(list_t *list, char *name, char *value);

/**
*? mem_set.c
*/
void mem_set(char **str, int len);
void set_shell_env(list_t *l_env, char ***env, char *fname);

/**
*? my_str_to_word_array_v2.c
*/
void set_var_v2(char **str, int *size, int *nb, char *str_cmp);
int cnt_wrd_v2(char *str, char *str_cmp);
int test_if_str_cmp(char *str, int size, char *str_cmp);
char **my_str_to_word_array_v2(char *str, char *str_cmp);

/**
*? paths_set_shell_env.c
*/
char **get_paths(char **env);

/**
*? pipe.c
*/
int verrif_input_after_pipe(char *input, char **arr_input);
void pipe_cmd(pipe_f_t *pipe_f, int i);
void pipe_cmd_end(pipe_f_t *pipe_f, int i);
void pipe_function(pipe_f_t *pipe_f);

/**
*? print_error.c
*/
void print_error(char *cmd, int err);
void print_segflt_floatex(int status);

/**
*? paths_set_shell_env.c
*/
char **get_paths(char **env);
void set_shell_env(list_t *l_env, char ***env, char *fname);

/**
*? prompt_format.c
*/
char *return_user(list_t *list);
char *parse_host(char *str);
char *return_host(list_t *list);
char *return_current_folder_next(list_t *list, elem_t *elem);
char *return_current_folder(list_t *list);

/**
*? prompt.c
*/
void my_putinv(char *str);
void prompt(list_t *l_env);

/**
*? read_inputs.c
*/
int prompt_getline(list_t *l_env, char **input, exit_t *exit_val);
void exec_cmds(char *input, char ***env, list_t *l_env, char ***arr_paths);
int read_input(char ***env, list_t *l_env, char ***arr_paths,
exit_t *exit_val);

/**
*? redirections.c
*/
void exec_one_right_redirect(char *file_name);
void exec_two_right_redirect(char *file_name);
int redirections(char *input, char ***arr_inputs);

/**
*? setenv.c
*/
void set_list_to_env(list_t *l_env, char ***env);
int str_name_is_valid(char *str);
void made_set_env(char **arr_inputs, char ***env, list_t *l_env);
void set_env(char **arr_inputs, char ***env, list_t *l_env);

/**
*? str_array_len.c
*/
int str_array_len(char **arr);

/**
*? unsetenv.c
*/
void unset_env(char **arr_inputs, char ***env, list_t *l_env);

#endif /* !MATCHSTICK_H_ */
