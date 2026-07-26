// Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to
// use a function for conversion.

#include <stdio.h>
// Prints temperature conversions from fahrenheit to celsius from 0 to 300

void fahr_cel(float upper, float step);

float lower, upper, step;
float fahr, celsius;

int main() {

  lower = 0.0;
  upper = 300.0;
  step = 20.0;

  fahr = lower;

  // Heading
  printf("=====================\n");
  printf("Fahr to Celsius table\n");
  printf("=====================\n");

  printf("Fahr          Celsius\n");

  fahr_cel(upper, step);
}

void fahr_cel(float upper, float step) {
  extern float fahr, celsius;
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%6.2f%15.2f\n", fahr, celsius);
    fahr = step + fahr;
  }
}
