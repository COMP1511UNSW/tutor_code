#include <stdio.h>

struct colour {
    int red;
    int green;
    int blue;
};

enum main_colours {
    RED,
    GREEN,
    BLUE,
    OTHER,
};

// -----------------------------------------------------------------------------

int main(void) {

    int r = 1;
    int g = 2;
    int b = 3;

    // Function has a structure of:
    // return_type name(arguments) {
    // 
    // }
    
    // Note that the name of the variables being passed into the function does
    // not need to match the name of the variables in the functions argument
    // list.

    // Also, when calling a function, just need to pass in the names of the
    // inputs, i.e. ...(r, g, b) instead of ...(int r, int g, int b).

    // Also, you have a void function, you can just call the function
    // i.e. function_name();

    // However, if you have a non-void function, you might want to catch the
    // return value and assign it back into a variable, such as below.
    struct colour my_colour = make_colour(r, g, b);
}

struct colour make_colour(int red, int green, int blue) {
    struct colour my_colour;
    my_colour.red = red;
    my_colour.green = green;
    my_colour.blue = blue;
    return my_colour;
}

// Completed code from the Kahoot ----------------------------------------------

enum main_colours get_main_colour(struct colour c) {
    if (c.red > c.green && c.red > c.blue) {
        return RED;
    } else if (c.green > c.red && c.green > c.blue) {
        return GREEN;
    } else if (c.blue > c.red && c.blue > c.green) {
        return BLUE;
    } else {
        return OTHER;
    }
}

double brightness(struct colour colour) {
    return sqrt(colour.red) + sqrt(colour.green) + sqrt(colour.blue);
}

double average_brightness(struct colour colours[100], int size) {
    double avg = 0;

    int i = 0;
    while (i < size) {
        avg += brightness(colours[i]);
        i++;
    }

    return avg / size;
}