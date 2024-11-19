/*
** EPITECH PROJECT, 2024
** my_strlowcase.c
** File description:
** task09
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int i;
    char *temp = my_strdup(str);

    for (i = 0; temp[i] != '\0'; i++) {
        if ((temp[i] >= 65) && (temp[i] <= 90))
            temp[i] += 32;
    }
    return temp;
}
