/*
 * Programmer: Allyson Morris and Krishna Swaminathan
 * 
 * Lab 1 - Part 2, Question 2
 *
 * Problem: This program shows basic input and output in C. 
 * It does simple math operations and string manipulation 
 * based on input.
 *
 * Solution Method: 
 * - The program has three functions:
 *   1) sum_integers: asks the user for two integers, sums them, and prints the result.
 *   2) multiply_floats: asks the user for two floats, multiplies them, and prints the result.
 *   3) echo_word: asks the user for a word and prints it twice.
 * - The main function calls these functions to execute the program.
 */

#include <stdio.h>

// Function to ask the user for two integers, calculate their sum, and print the result
void sum_integers() {
    int a, b;
    printf("Give two integers: ");
    scanf("%d %d", &a, &b);
    printf("You entered %d and %d, their sum is: %d\n", a, b, a + b);
}

// Function to ask the user for two floats, calculate their product, and print the result
void multiply_floats() {
    float x, y;
    printf("Give two floats: ");
    scanf("%f %f", &x, &y);
    printf("You entered %f and %f, their product is: %f\n", x, y, x * y);
}

// Function to ask the user for a word and print it twice
void echo_word() {
    char word[100];
    printf("Give a word: ");
    scanf("%s", word);
    printf("%s %s\n", word, word);
}

// Calls all other functions to run the program
int main(void) {
    // Calls sum_integers to add two integers
    sum_integers();
    // Calls multiply_floats to multiply two floats
    multiply_floats();
    // Calls echo_word to print a word twice
    echo_word();

    return 0;
}
