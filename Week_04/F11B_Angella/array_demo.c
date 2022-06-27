#include <stdio.h>

#define SIZE 10

int main(void) {

    // If you want to make an array with unitialised values:
    // int numbers[SIZE];
    // Just note that you won't be able to loop through this array and print
    // out its values if you haven't set its values.

    // If you want to make an array with all values initialised to 0:
    // int numbers[SIZE] = {0};

    // Make an array of 10 integers and loop through and print the values.
    int numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int index = 0;
    while (index < SIZE) {
        printf("%d\n", numbers[index]);
        index++;
    }

    return 0;
}