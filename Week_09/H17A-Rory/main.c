
#include <stdlib.h>

#include "list.h"

int main(void) {
    struct node *head = NULL;
    head = add_last(head, 1);
    head = add_last(head, 2);
    head = add_last(head, 3);
        
    struct node *head_copy = copy(head);
    
    head->data = 5;
    add_last(head_copy, 100);
    print_list(head);
    print_list(head_copy);
    return 0;
}

