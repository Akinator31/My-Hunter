/*
** EPITECH PROJECT, 2024
** mylist.h
** File description:
** header file for linked list structure
*/

#ifndef MYLIST_H
    #define MYLIST_H
    #include <dirent.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include "my_list.h"

typedef struct linked_list_s linked_list_t;
typedef struct node_s node_t;

struct node_s {
    void *data;
    node_t *next;
};

struct linked_list_s {
    node_t *head;
    node_t *tail;
    int size;
    int data_size;
};

linked_list_t *new_list(int data_size);
int is_empty_list(linked_list_t *list);
linked_list_t *push_back_list(linked_list_t *list, void *data);
linked_list_t *push_front_list(linked_list_t *list, void *data);
linked_list_t *pop_back_list(linked_list_t *list);
linked_list_t *pop_front_list(linked_list_t *list);
linked_list_t *clear_list(linked_list_t *list);
node_t *get_node(linked_list_t *list, int index);

#endif
