#include <stdio.h>

#define MAX_STR_SIZE 1024

char *my_fgets(char *str, int size);

int main(void) {
    char my_string[MAX_STR_SIZE];
    if (my_fgets(my_string, MAX_STR_SIZE) == NULL) {
        printf("Nothing was scanned in!\n");
    } else {
        printf("%s", my_string);
    }
    return 0;
}

/*
You'll want to keep in mind the following properties of fgets:

Scans characters into str (an array of chars) until either
    1. A '\n' is scanned in to the array:
        - str is returned (with the '\n' still at the end of the string).
    2. size - 1 characters are scanned in:
        str is returned.
    3. CTRL-D is pressed:
        if more than0 characters have been scanned in:
            str is returned.
        if 0 characters have been scanned in:
            NULL is returned.
*/
char *my_fgets(char *str, int size) {
    // DO NOT USE   scanf("%s", &str);
    
    int keep_looping = 1;
    int i = 0;
    while (keep_looping && i < size - 1 && scanf("%c", &str[i]) == 1) {
        if (str[i] == '\n') {
            keep_looping = 0;
        }
        i++;
    }
    
    if (i == 0) {
        return NULL;    
    }
    str[i] = '\0';
    
    return str;
}

