#include <stdio.h>

// Manually prints out a string, one character at a time.
// Should behave like printf("%s\n");
void print_string(char *string) {

    int i = 0;
    // Strings are like arrays, with a null terminator ('\0') at the
    // end to signify the end of the string.
    // ['M', 'a', 'n', 'y', ' ', 'c', 'h', 'a', 'r', 's', '\0']
    while (string[i] != '\0') {
        printf("%c", string[i]);
        i++;
    }
    
    printf("\n");
}

int main(void) {

    char my_string[] =  "Many chars";
    print_string(my_string);

    return 0;
}