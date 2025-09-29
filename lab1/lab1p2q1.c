#include <stdio.h>

// Function a
void print_half_message() {
    printf("One half is 50%%\n");
}

// Funciton b
void print_difference(int a, int b) {
    printf("The difference between %d and %d is %d\n", a, b, a - b);
}

// Function c
void print_division(float x, float y) {
    printf("%f / %f is %f\n", x, y, x / y);
}

//Values for functions
int main(void) {
    print_half_message();
    print_difference(10, 2);
    print_division(5.0, 2.0);

    return 0;
}
