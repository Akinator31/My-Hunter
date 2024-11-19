/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** info_list
*/

#include <stdlib.h>
#include "../../include/my_list.h"
#include "../my_lib/my.h"

linked_list_t *new_list(int data_size)
{
    linked_list_t *new_list = malloc(sizeof(*new_list));
    new_list = my_memset(new_list, 0, sizeof(linked_list_t));

    new_list->data_size = data_size;
    new_list->size = 0;
    new_list->head = NULL;
    new_list->tail = NULL;

    return new_list;
}

int is_empty_list(linked_list_t *list)
{
    if (list->head == NULL)
        return 1;
    return 0;
}

linked_list_t *clear_list(linked_list_t *list)
{
    node_t *temp_node = list->head;

    if (is_empty_list(list)) {
        return list;
    }
    while (list->head != NULL)
        list = pop_back_list(list);
    return list;
}

node_t *get_node(linked_list_t *list, int index)
{
    node_t *temp;

    if (index >= list->size) {
        printf("Index inexistant dans la liste\n");
        return NULL;
    }
    temp = list->head;
    for (int i = 0; i < index, temp != NULL; i++) {
        if (index == i)
            return temp;
        temp = temp->next;
    }
}