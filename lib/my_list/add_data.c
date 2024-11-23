/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** add_data
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "../../include/my_list.h"
#include "../my_lib/my.h"
#include <stdarg.h>

linked_list_t *push_front_list(linked_list_t *list, void *data)
{
    linked_list_t *new_element = malloc(sizeof(linked_list_t));

    new_element->data = data;
    new_element->next = list;
    return new_element;
}

linked_list_t *push_front_list_all(linked_list_t *list, int nb, ...)
{
    va_list args;
    linked_list_t *temp;

    va_start(args, nb);
    for (int i = 0; i < nb; i++) {
        list = push_front_list(list, va_arg(args, void *));
    }
    va_end(args);
    return list;
}
