#include <stdio.h>
#include <stdlib.h>

// Making a struct node.
struct node {
    int value;
    struct node *next;
};

// Function prototypes ---------------------------------------------------------

struct node *create_node(int value);
struct node *insert_at_head(struct node *head, int value);
struct node *insert_at_tail(struct node *head, int value);
struct node *delete_at_head(struct node *head);
struct node *delete_at_tail(struct node *head);
struct node *merge_two_sorted_lists(struct node *list_A, struct node *list_B);

// Main ------------------------------------------------------------------------

int main(void) {

    // Create two linked lists.

    struct node *list_A = insert_at_tail(NULL, 1);
    list_A = insert_at_tail(list_A, 2);
    list_A = insert_at_tail(list_A, 3);

    printf("First list is:\n");

    struct node *curr_A = list_A;
    while (curr_A != NULL) {
        printf("%d ", curr_A->value);
        curr_A = curr_A->next;
    }
    printf("\n");

    struct node *list_B = insert_at_tail(NULL, 1);
    list_B = insert_at_tail(list_B, 4);
    list_B = insert_at_tail(list_B, 5);
    list_B = insert_at_tail(list_B, 6);

    printf("Second list is:\n");

    struct node *curr_B = list_B;
    while (curr_B != NULL) {
        printf("%d ", curr_B->value);
        curr_B = curr_B->next;
    }
    printf("\n");

    struct node *list_C = merge_two_sorted_lists(list_A, list_B);

    printf("Resulting list is:\n");

    struct node *curr_C = list_C;
    while (curr_C != NULL) {
        printf("%d ", curr_C->value);
        curr_C = curr_C->next;
    }
    printf("\n");

    return 0;
}

// Helper functions ------------------------------------------------------------

// Returns a pointer to the new node.
struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the head of the linked list.
struct node *insert_at_head(struct node *head, int value) {
    struct node *new_node = create_node(value);
    new_node->next = head;
    head = new_node;
    return head;
}

// Insert a new node at the end of the linked list.
struct node *insert_at_tail(struct node *head, int value) {
    struct node *new_node = create_node(value);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
    return head;
}

// Delete the node at the head of the linked list.
struct node *delete_at_head(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *old_head = head;
    head = head->next;
    free(old_head);
    return head;
}

// Delete the node at the end of the linked list.
struct node *delete_at_tail(struct node *head) {
    // 1. List is empty.
    if (head == NULL) {
        return NULL;
    }
    // 2. List has 1 node.
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    // 3. Else.
    struct node *curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    return head;
}

// Without modifying list_A and list_B, return a new list that is a merge
// between list_A and list_B in sorted order.
struct node *merge_two_sorted_lists(struct node *list_A, struct node *list_B) {
    
    struct node *list_C = NULL;

    // If one list is empty, return the copy of the other list.
    if (list_A == NULL) {
        struct node *curr_B = list_B;
        while (curr_B != NULL) {
            list_C = insert_at_tail(list_C, curr_B->value);
            curr_B = curr_B->next;
        }
        return list_C;
    }
    if (list_B == NULL) {
        struct node *curr_A = list_A;
        while (curr_A != NULL) {
            list_C = insert_at_tail(list_C, curr_A->value);
            curr_A = curr_A->next;
        }
        return list_C;
    }

    // Loop through both lists until reaching the end of either one. As we are
    // looping through, add whichever value is smaller.
    struct node *curr_A = list_A;
    struct node *curr_B = list_B;
    while (curr_A != NULL && curr_B != NULL) {
        if (curr_A->value < curr_B->value) {
            list_C = insert_at_tail(list_C, curr_A->value);
            curr_A = curr_A->next;
        } else {
            list_C = insert_at_tail(list_C, curr_B->value);
            curr_B = curr_B->next;
        }
    }

    // Add the rest of the list.
    while (curr_A != NULL) {
        list_C = insert_at_tail(list_C, curr_A->value);
        curr_A = curr_A->next;
    }
    while (curr_B != NULL) {
        list_C = insert_at_tail(list_C, curr_B->value);
        curr_B = curr_B->next;
    }

    return list_C;
}