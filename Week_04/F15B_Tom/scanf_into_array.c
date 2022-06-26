#include <stdio.h>

#define MAX_VELOCITIES 100

int main (void) {
    // TODO: Declare array to store velocities
    int scanned_velocities[MAX_VELOCITIES];
    
    // TODO: check result of scanf()
    // index_and_total_velocities starts as an index
    int number_of_velocities = 0;
    int scanf_result = scanf(" %d", &scanned_velocities[number_of_velocities]);
    while (scanf_result == 1) {
        // index_and_total_velocities ends as a total 
        number_of_velocities++;
        
        scanf_result = scanf(" %d", &scanned_velocities[number_of_velocities]);
    }
    
    // TODO: find the sum of the last 5 elements
    
    // e.g. number_of_velocities is 5 (i.e. 5 elements),
    //      starting_index_of_5th_last == 0
    
    int starting_index_of_5th_last = number_of_velocities - 5;
    double avg = 0.0;
    while (starting_index_of_5th_last < number_of_velocities) {
        avg += scanned_velocities[starting_index_of_5th_last];
        
        starting_index_of_5th_last++;
    }
    
    // TODO: print avg
    printf("Average = %lf\n", avg / number_of_velocities);
    
    return 0;
}
