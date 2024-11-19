/*
** EPITECH PROJECT, 2024
** B-PSU-100-TLS-1-1-myls-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** remove_data
*/

#include <stdlib.h>
#include "../../include/my_list.h"

linked_list_t *pop_back_list(linked_list_t *list)
{
    node_t *temp = list->head;

    if (is_empty_list(list)) {
        return list;
    }
    if (list->size == 1) {
        free(list->head->data);
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size -= 1;
        return list;
    }
    while (temp->next != list->tail) {
        temp = temp->next;
    }
    free(temp->next->data);
    free(temp->next);
    temp->next = NULL;
    list->tail = temp;
    list->size -= 1;
    return list;
}

linked_list_t *pop_front_list(linked_list_t *list)
{
    node_t *temp = list->head->next;

    if (is_empty_list(list)) {
        return list;
    }
    if (list->size == 1) {
        free(list->head->data);
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size -= 1;
        return list;
    }
    free(list->head->data);
    free(list->head);
    list->head = temp;
    return list;
}
