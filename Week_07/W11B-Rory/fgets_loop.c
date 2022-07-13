
#include <stdio.h>

#define MAX_STR_SIZE 100
int main(void) {
    char str[MAX_STR_SIZE];
    while (fgets(str, MAX_STR_SIZE, stdin) != NULL) {
        printf("%s", str);
    }
    return 0;
}

