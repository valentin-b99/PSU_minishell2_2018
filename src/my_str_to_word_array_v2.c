/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../include/my.h"
#include <stdlib.h>

void set_var_v2(char **str, int *size, int *nb, char *str_cmp)
{
    *str += *size;
    *size = 0;
    *nb += 1;
}

int cnt_wrd_v2(char *str, char *str_cmp)
{
    int size = 0;

    for (int i = 0; str[i]; i++)
        if (!my_strncmp(str + i, str_cmp, my_strlen(str_cmp) - 1) &&
            str[i + my_strlen(str_cmp)] != str_cmp[0] &&
            str[i - 1] != str_cmp[0])
            size++;
    return (size);
}

int test_if_str_cmp(char *str, int size, char *str_cmp)
{
    if (my_strncmp(str + size, str_cmp, my_strlen(str_cmp) - 1))
        return (1);
    else if (!my_strncmp(str + size, str_cmp, my_strlen(str_cmp) - 1) &&
        (str[size + my_strlen(str_cmp)] == str_cmp[0] ||
        str[size - 1] == str_cmp[0]))
        return (1);
    return (0);
}

char **my_str_to_word_array_v2(char *str, char *str_cmp)
{
    char **result;
    int size = 0;
    int nb = 0;

    if ((result = malloc(sizeof(char *) * (cnt_wrd_v2(str, str_cmp) + 2))) ==
        NULL)
        return (NULL);
    while (str && str[size]) {
        while (test_if_str_cmp(str, size, str_cmp) && str[size])
            size++;
        if ((result[nb] = malloc(sizeof(char) * size + 1)) == NULL)
            return (NULL);
        result[nb] = my_strncpy(result[nb], str, size);
        while (str[size] == str_cmp[0] && str[size])
            size++;
        set_var_v2(&str, &size, &nb, str_cmp);
    }
    result[nb] = NULL;
    return (result);
}