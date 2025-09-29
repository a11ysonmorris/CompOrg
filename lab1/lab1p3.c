#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

// reverse a word between start and end pointers
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
    char input[MAX_LEN];
    char output[MAX_LEN];

    FILE *fin = fopen("lab1p3in", "r");
    FILE *fout = fopen("lab1p3out", "w");

    if (fin == NULL || fout == NULL) {
        printf("File error\n");
        return 1;
    }

    // read one line
    if (fgets(input, MAX_LEN, fin) == NULL) {
        printf("No input\n");
        return 1;
    }

    char *in_ptr = input;
    char *out_ptr = output;
    char *word_start = NULL;

    while (*in_ptr != '\0') {
        if (isalpha(*in_ptr)) {
            if (word_start == NULL) {
                word_start = out_ptr;
            }
            *out_ptr = toupper(*in_ptr);
        } else {
            if (word_start != NULL) {
                reverse_word(word_start, out_ptr - 1);
                word_start = NULL;
            }
            if (*in_ptr == '_') {
                *out_ptr = ' ';
            } else {
                *out_ptr = *in_ptr;
            }
        }
        in_ptr++;
        out_ptr++;
    }

    if (word_start != NULL) {
        reverse_word(word_start, out_ptr - 1);
    }

    *out_ptr = '\0';

    fputs(output, fout);

    fclose(fin);
    fclose(fout);

    return 0;
}

