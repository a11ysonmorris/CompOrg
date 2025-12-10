#include <stdio.h>
#include <stdlib.h>  // for atoi

/* Calculates the square of integer x */
int sq (int x) {
  return x*x;
}

/* Calculates the sum of squares of integers y and z */
int sos (int y, int z) {
  return sq(y) + sq(z);
}

/* Reads two integer inputs from command line and displays result of SOS program */
int main (int argn, char** argv) {
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  printf("sos(%i,%i)=%i\n", a, b, sos(a,b));
  return 0;
}
  
