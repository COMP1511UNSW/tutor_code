#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void) {

    int length = 0;

    printf("Enter size: ");
    scanf(" %d", &length);

    // int nums[SIZE];

    int *num_ptr;
    num_ptr = malloc(length * sizeof(int));

    int i = 0;
    while (i < length) {
        num_ptr[i] = 2 + i;
        printf("Array %d: %d\n", i, num_ptr[i]);
        i++;
    }

    
    int new_length;
    printf("Enter new size: ");
    scanf(" %d", &new_length);

    num_ptr = realloc(num_ptr, sizeof(int) * new_length);


    int j = length;
    while (j < new_length) {
        num_ptr[j] = 5;
        printf("Array %d: %d\n", j, num_ptr[j]);
        j++;
    }

    free(num_ptr);

    return 0;
}
