#include <stdio.h>

int main(void) {

    // Create an int variable;
    // Address 0xFF00
    int var = 3;

    // Creating an int pointer -> ptr;
    int *ptr;
    
    // Print the address that ptr stores;
    ptr = &var;

    // Getting the address of a variable;
    // Prints out 0xFF00 (which is the address of
    // var).
    printf("%p\n", ptr);
    
    // Accessing memory via a pointer;
    // Prints out the value of var which is 3.
    printf("%d\n", *ptr);

    return 0;
}