
#include <stdlib.h>

#include "list.h"

int main(void) {
    struct node *head = NULL;
    head = add_last(head, 1);
    head = add_last(head, 2);
    head = add_last(head, 3);
    
    struct node *new_head = copy(head);
    
    print_list(head);
    print_list(new_head);
    return 0;
}
