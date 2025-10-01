/*
 * Programmer: Allyson Morris & Krishna Swaminathan 
 * 
 * Lab 1 - Part 2, Question 1
 *
 * Problem: This program highlights basic functions in C. 
 * It prints a message, calculates the difference between two integers, 
 * and performs a division of two floating-point numbers.
 *
 * Solution Method: 
 * - The program has three functions: 
 *   1) print_half_message: prints a message.
 *   2) print_difference: takes two integers, calculates their difference, and prints it.
 *   3) print_division: takes two floats, divides them, and prints the result.
 * - The main function calls these three functions with example values.
 */

#include <stdio.h>

// Function a: print a message
void print_half_message() {
    printf("One half is 50%%\n");
}

//Function b: calculate and print the difference between two integers
void print_difference(int a, int b) {
    printf("The difference between %d and %d is %d\n", a, b, a - b);
}

// Function c: calculate and print the division of two floating-point numbers
void print_division(float x, float y) {
    printf("%f / %f is %f\n", x, y, x / y);
}

// Call each function with example values 
int main(void) {
     // Prints the half message
    print_half_message();
    // Calculate and print the difference between 10 and 2
    print_difference(10, 2);
    // Calculate and print the division of 5.0 by 2.0
    print_division(5.0, 2.0);

    return 0;
}
