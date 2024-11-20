/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** add_data
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "../../../include/my_list.h"
#include "../my.h"
#include <string.h>

linked_list_t *push_front_list(linked_list_t *list, void *data)
{
    linked_list_t *new_element = malloc(sizeof(linked_list_t));

    new_element->data = data;
    new_element->next = list;
    return new_element;
}
