/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../../include/my.h"
#include <stdlib.h>

void jump_char_start(char **str, char *list_char, int size)
{
    while (char_in_list((*str)[size], list_char) && (*str)[size])
        *str += 1;
}

void set_var(char **str, int *size, int *nb)
{
    *str += *size;
    *size = 0;
    *nb += 1;
}

int cnt_wrd(char *str, char *list_char)
{
    int size = 0;

    for (int i = 0; str[i]; i++)
        if (char_in_list(str[i], list_char))
            size++;
    return (size);
}

char **my_str_to_word_array(char *str, char *list_char)
{
    char **result;
    int size = 0;
    int nb = 0;

    if ((result = malloc(sizeof(char *) * (cnt_wrd(str, list_char) + 2))) ==
        NULL)
        return (NULL);
    jump_char_start(&str, list_char, size);
    while (str[size]) {
        while (!char_in_list(str[size], list_char) && str[size])
            size++;
        if ((result[nb] = malloc(sizeof(char) * size + 1)) == NULL)
            return (NULL);
        result[nb] = my_strncpy(result[nb], str, size);
        while (char_in_list(str[size], list_char) && str[size])
            size++;
        set_var(&str, &size, &nb);
    }
    result[nb] = NULL;
    return (result);
}
