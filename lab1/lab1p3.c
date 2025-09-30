/*
 * Programmer: Allyson Morris
 * 
 * Lab 1 - Part 3
 *
 * Problem: This program reads a single line from an input file, reverses 
 * each word while keeping non-alphabetic characters in place, converts letters 
 * to uppercase, which is then put in an output file.
 *
 * Solution Method: 
 * - Open input and output files.
 * - Read one line of input.
 * - Use pointers to iterate through the line:
 *   - Identify words as sequences of alphabetic characters.
 *   - Convert letters to uppercase.
 *   - Reverse each word in place when a non-alphabetic character is found.
 *   - Replace underscores with spaces and leave other non-alphabetic characters unchanged.
 * - Write the processed line to the output file and close files.
 */


#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

// Function to reverse a word between two pointers
void reverse_word(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(void) {
    char input[MAX_LEN]; // line from input file
    char output[MAX_LEN]; // stores the processed output

    // Open input and output files
    FILE *fin = fopen("lab1p3in", "r");
    FILE *fout = fopen("lab1p3out", "w");

    if (fin == NULL || fout == NULL) {
        printf("File error\n");
        return 1;
    }

    // Read one line from input file
    if (fgets(input, MAX_LEN, fin) == NULL) {
        printf("No input\n");
        return 1;
    }

    char *in_ptr = input;  // pointer for input buffer
    char *out_ptr = output;   // pointer for output buffer
    char *word_start = NULL;  // pointer to the beginning of the current word

     // Process each character
    while (*in_ptr != '\0') {
        if (isalpha(*in_ptr)) {
            if (word_start == NULL) {
                word_start = out_ptr;
            }
            *out_ptr = toupper(*in_ptr);  // convert letter to uppercase
        } else {
             // At end of the word, reverse it
            if (word_start != NULL) {
                reverse_word(word_start, out_ptr - 1);
                word_start = NULL;
            }
            // Replace underscores with spaces, keep other characters
            if (*in_ptr == '_') {
                *out_ptr = ' ';
            } else {
                *out_ptr = *in_ptr;
            }
        }
        in_ptr++;
        out_ptr++;
    }

    // Reverse last word if input ends with a word
    if (word_start != NULL) {
        reverse_word(word_start, out_ptr - 1);
    }

    // Terminate the output string
    *out_ptr = '\0';

    // Write to output file
    fputs(output, fout);

    // Close files
    fclose(fin);
    fclose(fout);

    return 0;
}

