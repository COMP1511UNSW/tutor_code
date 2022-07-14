
#include <stdio.h>

// Manually prints out a string, one character at a time.
// Should behave like printf("%s\n");
void print_string(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        printf("%c", string[i]);
        i++;
    }
    printf("\n");
}



int main (void) {
    // char string1[100] = {'h', 'e', 'l', 'l', 'o', '\n', '\0'};
    // char string2[100] = "hello\n";
    // char string3[] = "hello\n";
    // char *string4 = "hello\n";
    
    char string[] = "Hello \0world!\n";
    print_string(string);
    printf("%s", string);
    return 0;
}























