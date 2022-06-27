#include <stdio.h>

int main(void) {

    int num;

    // Scanning in one time.
    scanf("%d", &num);

    // Scanning in three times.
    int i = 0;
    while (i < 3) {
        scanf("%d", &num);
    }

    // Scanning in until Ctrl+D.
    // scanf returns the number of successful scans.
    // When the user input Ctrl+D, scanf returns -1.
    while (scanf("%d", &num) == 1) {
        printf("The number scanned in was %d.\n", num);
    }

    return 0;
}
