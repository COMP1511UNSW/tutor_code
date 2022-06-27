#include <stdio.h>

#define MAX 10
#define HUNDRED 100

void odd_only(void);
void copy_array(void);

int main(void) {
    odd_only();
    copy_array();
}

// Create three procedures, named "odd_only", "copy_array", and "largest_character"
void odd_only(void) {

    // Create an integer array with at least 5 elements.
    int array[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Create a while loop which loops through every element of the array. 
    // You will also need a variable above the while loop.
    int i = 0;
    while (i < MAX) {
        // Write an if statment which adds one to variables in the while loop if 
        // they are even.
        if (array[i] % 2 == 0) {
            array[i]++;
        }
        i++;
    }
    // Write another while loop which goes through the array with a different 
    // iterator.
    int j = 0;
    while (j < MAX) {
        printf("%d ", array[j]);
        j++;
    }
    printf("\n");
}

void copy_array(void) {
    // Create an array of doubles with at least 3 elements.
    double array_one[MAX] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    // Create another double array of 100 elements; but every element 
    // initialised to 0.
    double array_two[HUNDRED] = {0};
    // Create a while loop which loops through every element of the first array.
    int i = 0;
    while (i < MAX) {
        // Copy the elements of the first array into the second array (leave 0's 
        // at the end).
        array_two[i] = array_one[i];
        i++;
    }
    // Create a while loop which prints out all the elements of the second array.
    int j = 0;
    while (j < MAX) {
        printf("%lf ", array_two[j]);
        j++;
    }
    printf("\n");
}