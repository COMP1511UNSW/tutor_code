#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int size) {
    int i = 0;
    while (i < size) {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
}

void dynamic_memory(int size) {

    // Create a dynamic array of integers, that is exactly `size`
    // integers long.
    int *array = malloc(sizeof(int) * size);

    // Set all the integers in that array to 0.
    int i = 0;
    while (i < size) {
        array[i] = 0;
        i++;
    }

    // Print the array.
    print_array(array, size);

    // Make that array twice as long.
    // realloc(pointer, new_size);
    // realloc will create the new block of memory with the 
    // larger size and copy the old data to that newly allocated 
    // memory and than it will deallocate the old memory area.
    array = realloc(array, size * 2);

    // Set all the new and undefined values of the array to 1.
    int j = size;
    while (j < size * 2) {
        array[j] = 1;
        j++;
    }

    // Print the updated array.
    print_array(array, size * 2);

    // Free the array.
    free(array);
}

int main(void) {

    int size = 5;
    dynamic_memory(size);

    return 0;
}

