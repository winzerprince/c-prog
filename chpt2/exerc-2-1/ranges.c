// Exercise 2-1. Write a program to determine the ranges of char, short, int,
// and long variables, both signed and unsigned, by printing appropriate values
// from standard headers and by direct computation. Harder if you compute them:
// determine the ranges of the various floating-point types

#include <float.h>
#include <limits.h>
#include <stdio.h>

// Prints out the ranges of char, short, int and long varialbes based on
// limits.h

int main() {
  printf("RANGES\n");
  printf("\nsigned int\n");
  printf("\tMIN: %d\n", INT_MIN);
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

  printf("\nsigned long\n");
  printf("\tMIN: %ld\n", LONG_MIN);
  printf("\tMAX: %ld\n", LONG_MAX);
  printf("\tWIDTH:2 ^ %d\n",
         (int)sizeof((unsigned long)LONG_MAX - LONG_MIN) * 8);

  printf("\nunsigned long\n");
  printf("\tMIN: %lu\n", ULONG_MAX - ((unsigned long)LONG_MAX - LONG_MIN));
  printf("\tMAX: %lu\n", ULONG_MAX);
  printf("\tWIDTH:2 ^ %d\n",
         (int)sizeof(ULONG_MAX -
                     (ULONG_MAX - ((unsigned long)LONG_MAX - LONG_MIN))) *
             8);

  // Floating point type ranges

  // For floating point types, the min represent smallest normalized positive
  // value rahter than negative value with greatest magnitude
  // NOTE: The minimum values used here represent those of float in normalized
  // form ie stored value = 1.mantissa x 2^exponent
  //
  // %e for scientific notation instead of %f, %lf or %Lf which would only use
  // 6dp

  printf("\nfloat\n");
  printf("\tMIN: %e\n", FLT_MIN);
  printf("\tMAX: %e\n", FLT_MAX);
  printf("\tSignificant digits: ~7\n");

  printf("\ndouble\n");
  printf("\tMIN: %e\n", DBL_MIN);
  printf("\tMAX: %e\n", DBL_MAX);
  printf("\tSignificant digits: ~15-17\n");

  printf("\nlong double\n");
  printf("\tMIN: %e\n", LDBL_MIN);
  printf("\tMAX: %e\n", LDBL_MAX);
  printf("\tSignificant digits: ~18-19\n");
}
