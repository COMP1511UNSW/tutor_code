#include <stdio.h>

#define MAX_STR_SIZE 1024

char *my_fgets(char *str, int size);

int main(void) {
    char string[MAX_STR_SIZE];
    if (my_fgets(string, MAX_STR_SIZE) == NULL) {
        printf("Nothing was input\n");
    } else {
        printf("%s", string);
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
    int i = 0;
    
    int keep_looping = 1;
    while (i < size - 1 && keep_looping && scanf("%c", &str[i]) == 1) {
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

