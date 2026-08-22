// Exercise 2-1. Write a program to determine the ranges of char, short, int,
// and long variables, both signed and unsigned, by printing appropriate values
// from standard headers and by direct computation. Harder if you compute them:
// determine the ranges of the various floating-point types

#include <limits.h>
#include <stdio.h>

// Prints out the ranges of char, short, int and long varialbes based on
// limits.h

int main() {
  printf("RANGES\n");
  printf("\nsigned int\n");
  printf("\tMIN: %ld\n", INT_MIN);
  printf("\tMAX: %ld\n", INT_MAX);
  printf("\tWIDTH: %ld\n", ((long)INT_MAX - INT_MIN + 1));

  printf("\nunsigned int\n");
  printf("\tMIN: %ld\n", UINT_MAX - ((long)INT_MAX - INT_MIN));
  printf("\tMAX: %ld\n", UINT_MAX);
  printf("\tWIDTH: %ld\n",
         ((long)UINT_MAX - (UINT_MAX - ((long)INT_MAX - INT_MIN)) + 1));

  printf("\nsigned short\n");
  printf("\tMIN: %hd\n", SHRT_MIN);
  printf("\tMAX: %ld\n", SHRT_MAX);
  printf("\tWIDTH: %ld\n", ((long)SHRT_MAX - SHRT_MIN + 1));

  printf("\nunsigned short\n");
  printf("\tMIN: %hu\n", USHRT_MAX - (SHRT_MAX - SHRT_MIN));
  printf("\tMAX: %hu\n", USHRT_MAX);
  printf("\tWIDTH: %d\n", USHRT_MAX - (USHRT_MAX - (SHRT_MAX - SHRT_MIN)) + 1);

  printf("\nsigned char\n");
  printf("\tMIN: %d\n", CHAR_MIN);
  printf("\tMAX: %d\n", CHAR_MAX);
  printf("\tWIDTH: %d\n", (CHAR_MAX - CHAR_MIN + 1));

  printf("\nunsigned char\n");
  printf("\tMIN: %d\n", UCHAR_MAX - (CHAR_MAX - CHAR_MIN));
  printf("\tMAX: %d\n", UCHAR_MAX);
  printf("\tWIDTH: %d\n",
         (UCHAR_MAX - (UCHAR_MAX - (CHAR_MAX - CHAR_MIN)) + 1));
}
