// Program to show creation of linked lists in C
// Written by Rory Golledge, z5308772

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *new_node(int data);
struct node *add_to_head(struct node *old_head, int data);
void print_list(struct node *head);
void print_last_node(struct node *head);

int main(void) {
    struct node *head;
    head = NULL;
    
    // Add 10 nodes to the list. Since we are adding to the head, nodes
    // will appear in reverse order to that which they are added.
    int i = 0;
    while (i < 10) {
        head = add_to_head(head, i);
        i++;
    }
    
    // Naive printing of list (without loops)
    /*printf("%d\n", head->data);
    printf("%d\n", head->next->data);
    printf("%d\n", head->next->next->data);
    printf("%d\n", head->next->next->next->data);*/
    
    printf("Whole list:\n");
    print_list(head);
    
    printf("Last node: ");
    print_last_node(head);
    return 0;
}

// Create a new node with the given `data` and returns a pointer to it
struct node *new_node(int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    
    return new;
}

// Take in an `old_head` and append a new `struct node *` before it, then
// returns this new head
struct node *add_to_head(struct node *old_head, int data) {
    struct node *new_head = new_node(data);
    new_head->next = old_head;
    
    return new_head;
}

// Prints an entire linked list given a `head`
void print_list(struct node *head) {
    struct node *current = head;       // int i = 0;
    while (current != NULL) {          // while (i < SIZE) {
        printf("%d\n", current->data); //     printf("%d\n", array[i]);
        current = current->next;       //     i = i + 1;
    }                                  // }
}

// Prints the `data` value of the last node in the given `head`
// list. Prints "List is empty\n" if no nodes exist in the list.
void print_last_node(struct node *head) {
    // We cannot print the last node if the list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    // Loop until we reach the last node, but don't go further
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    // curr always points at the last node at this point in time
    printf("%d\n", curr->data);
}


