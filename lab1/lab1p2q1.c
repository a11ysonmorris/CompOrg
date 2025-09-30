/*
 * Programmer: Allyson Morris
 * 
 * Lab 1 - Part 2, Question 1
 *
 * Problem: This program highlights basic functions in C. 
 * It prints a message, calculates the difference between two integers, 
 * and performs a division of two floating-point numbers.
 *
 * Solution Method: 
 * - The program has three functions: 
 *   1) print_half_message: prints a static message.
 *   2) print_difference: takes two integers, calculates their difference, and prints it.
 *   3) print_division: takes two floats, divides them, and prints the result.
 * - The main function calls these three functions with example values.
 */

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
