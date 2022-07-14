
#include <stdio.h>

// Functions to implement:

// 1.
// returns the number of lowercase letters in `char *string`
int count_lowercase(char *string) {
    int i = 0;
    int n_lowercase = 0;
    while (string[i] != '\0') {
        if (is_lowercase(string[i])) {
            // Found a lowercase letter
            n_lowercase++;
        }
        i++;
    }
    return n_lowercase;
}

// 2.
// modifies `char *string` by converting all its vowels to uppercase
void make_vowels_uppercase(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        if (is_vowel(string[i])) {
            string[i] = to_uppercase(string[i]);
        }
        i++;
    }
}

// 3..
// shortens a string so that it ends after the first word
// e.g. "This is a sentence" should turn into:
//      "This"
// 
// (hint. what defines when a string ends?)
void delete_following_words(char *string) {
    int i = 0;
    while (string[i] != ' ' && string[i] != '\0') {
        i++
    }
    string[i] = '\0';
}

