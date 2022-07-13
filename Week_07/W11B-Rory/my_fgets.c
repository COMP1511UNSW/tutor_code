#include <stdio.h>


char *my_fgets(char *str, int size);

int main(void) {
    char string[10];
    if (my_fgets(string, 10) == NULL) {
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
    
    int index = 0;
    int end_loop = 0;
    while (index < size - 1 && end_loop == 0 && scanf("%c", &str[index]) == 1) {
        if (str[index] == '\n') {
            end_loop = 1;
        }
        index++;
    }
    
    if (index == 0) {
        return NULL;
    }
    
    str[index] = '\0';
    
    return str;
}

