/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** add_data
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "../../include/my_list.h"
#include "../../lib/my_lib/my.h"
#include <string.h>

linked_list_t *push_back_list(linked_list_t *list, void *data)
{
    node_t *new_element = (node_t *)malloc(sizeof(*new_element));
    new_element = memset(new_element, 0, list->data_size);
    new_element->data = malloc(list->data_size);
    memcpy(new_element->data, data, list->data_size);

    if (is_empty_list(list)) {
        list->head = new_element;
        list->tail = new_element;
        list->size += 1;
        return list;
    } 

    list->tail->next = new_element;
    list->tail = new_element;
    list->size += 1;
    return list;
}

linked_list_t *push_front_list(linked_list_t *list, void *data)
{
    node_t *new_element = (node_t *)malloc(sizeof(*new_element));
    new_element = memset(new_element, 0, list->data_size);
    new_element->data = malloc(list->data_size);
    memcpy(new_element->data, data, list->data_size);

    if (is_empty_list(list)) {
        list->head = new_element;
        list->tail = new_element;
        list->size += 1;
        return list;
    } 

    new_element->next = list->head;
    list->head = new_element;
    list->size += 1;
    return list;
}
