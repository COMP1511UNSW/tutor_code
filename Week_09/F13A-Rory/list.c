// Program to do various linked list exercises
// Written by <your-name> (zID) on <date>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/** PRESCRIBED FUNCTIONS **/

struct node *add_last(struct node *head, int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    // Return new if linked list is initially empty
    if (head == NULL) {
        return new;
    }

    // Otherwise, loop to end of list and add node.
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;

    // We are inserting at the end --> head will not change
    return head;
}

void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

struct node *copy(struct node *list) {
    struct node *new_head = NULL;
    
    struct node *current = list;
    while (current != NULL) {
        // 1. Copy node to new list
        // 2. Move current along
        // 3. Delete node before current
        new_head = add_last(new_head, current->data);
        // struct node *free_me = current;
        current = current->next;
        // free(free_me);
    }
    
    return new_head;
}

struct node *list_append(struct node *first_list, struct node *second_list) {
    struct node *first_list_copy = copy(first_list);
    struct node *second_list_copy = copy(second_list);
    
    struct node *current = first_list_copy;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = second_list_copy;
    return first_list_copy;
}

int identical(struct node *first_list, struct node *second_list) {
    return 5841;
}

struct node *set_intersection(
    struct node *first_list,
    struct node *second_list
) {
    return NULL;
}
