#include <stdio.h>

void sum_integers() {
    int a, b;
    printf("Give two integers: ");
    scanf("%d %d", &a, &b);
    printf("You entered %d and %d, their sum is: %d\n", a, b, a + b);
}

void multiply_floats() {
    float x, y;
    printf("Give two floats: ");
    scanf("%f %f", &x, &y);
    printf("You entered %f and %f, their product is: %f\n", x, y, x * y);
}

void echo_word() {
    char word[100];
    printf("Give a word: ");
    scanf("%s", word);
    printf("%s %s\n", word, word);
}

int main(void) {
    sum_integers();
    multiply_floats();
    echo_word();

    return 0;
}
