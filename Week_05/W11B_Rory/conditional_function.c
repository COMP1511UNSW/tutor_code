#include <stdio.h>

int is_a_letter(char ch);

int main(void) {

    int ch = 'b';

    printf("Is %c a letter?\n", ch);
    if (is_a_letter(ch)) {
        printf("Yes.\n");
    } else {
        printf("No.\n");
    }

    return 0;
}

// Using a function to check for certain conditions is a lot neater
// than putting the conditions in the if statement.
int is_a_letter(char ch) {
    // Returns 1 if the conditions are met.
    // Else, returns 0.
    return (
        ('a' <= ch && ch <= 'z') ||
        ('A' <= ch && ch <= 'Z' )
    );
}