#include <stdio.h>

#define MAX_SIZE 1024

char *my_fgets(char *str, int size) {

    // Scans characters into str (an array of chars) until either
        // A '\n' is scanned in to the array:
             // str is returned (with the “\n” still at the end of the string).
        // size - 1 characters are scanned in:
            // str is returned.
        // CTRL-D is pressed:
            // if more than 0 characters have been scanned in:
                // str is returned.
            // if 0 characters have been scanned in:
                // NULL is returned.
    // If any characters were scanned in, then a '\0' is added to the array after 
    // the last character.

    // If array size is invalid, return NULL -> no valid strings.
    if (size < 1) {
        return NULL;
    } else if (size == 1) {
        // If string size is just 1, it has to store '\0' because all strings
        // need a null terminator.
        str[0] = '\0';
        return str;
    }

    // Account for the case where user Ctrl-D without giving any characters.
    char c;
    int scanf_return_value = scanf("%c", &c);
    if (scanf_return_value != 1) {
        return NULL;
    }

    int end_of_line = 0;
    int i = 0;
    // Note that the while loop has 3 conditions to account for the 3/4
    // specified conditions.
    while (i < size - 1 && end_of_line == 0 && scanf_return_value == 1) {
        str[i] = c;
        // If a newline is given, we have reached the end of line.
        if (c == '\n') {
            end_of_line = 1;
        } else {
            // If a newline is not given, keep scanning in values.
            scanf_return_value = scanf("%c", &c);
        }
        i++;
    }

    // Add a null terminator at the end of the string to signal end of string.
    str[i] = '\0';
    return str;
}

int main(void) {
    char str[MAX_SIZE];
    my_fgets(str, MAX_SIZE);
    return 0;
}

