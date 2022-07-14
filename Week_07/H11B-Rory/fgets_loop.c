
#include <stdio.h>

#define MAX_STR_SIZE 1024

int main(void) {
    char my_string[MAX_STR_SIZE];
    while (fgets(my_string, MAX_STR_SIZE, stdin) != NULL) {
        printf("%s", my_string);
    }
    return 0;
}

