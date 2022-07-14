
#include <stdio.h>

#define MAX_STR_SIZE 1024

int main(void) {
    char string[MAX_STR_SIZE];
    while (fgets(string, MAX_STR_SIZE, stdin) != NULL) {
        printf("%s", string);
    }
    return 0;
}
g
