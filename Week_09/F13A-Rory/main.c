
#include <stdlib.h>

#include "list.h"

int main(void) {
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    
    list1 = add_last(list1, 1);
    list1 = add_last(list1, 2);
    list1 = add_last(list1, 3);
    list1 = add_last(list1, 4);
    
    list2 = add_last(list2, 5);
    list2 = add_last(list2, 6);
    list2 = add_last(list2, 7);
    
    print_list(list1);
    print_list(list2);
    
    struct node *list3 = list_append(list1, list2);
    
    print_list(list3);
    
    print_list(list1);
    print_list(list2);
    
    return 0;
}

