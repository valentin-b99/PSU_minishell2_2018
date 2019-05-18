/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../include/minishell.h"

exit_t init_exit_struct(void)
{
    exit_t exit_val;

    exit_val.display = 0;
    exit_val.value = -1;
    return (exit_val);
}

int after_read(exit_t exit_val)
{
    if (exit_val.display)
        my_putstr(CMD_EXIT);
    my_putinv("\n");
    if (exit_val.value > -1)
        return (exit_val.value);
}

void free_list(list_t *list)
{
    elem_t *elem;

    while (elem) {
        elem = list->first;
        list->first = elem->next;
        free(elem->name);
        free(elem->value);
        free(elem);
    }
    free(list);
}

int my_shell(char **env, char *fname)
{
    char **arr_paths = get_paths(env);
    list_t *l_env;
    exit_t exit_val = init_exit_struct();

    if ((l_env = malloc(sizeof(list_t))) == NULL)
        exit(84);
    fill_struct(l_env, env);
    set_shell_env(l_env, &env, fname);
    while (42) {
        if (!read_input(&env, l_env, &arr_paths, &exit_val)) {
            free(l_env);
            return (after_read(exit_val));
        }
    }
    free(arr_paths);
    free_list(l_env);
}

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return (84);
    if (str_array_len(env) < 1)
        return (84);
    return (my_shell(env, av[0] + 1));
}
