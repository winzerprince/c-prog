#include <stdio.h>
// Prints temperature conversions from fahrenheit to celsius from 0 to 300
int main() {

  float lower, upper, step;
  float fahr, celsius;

  lower = 0.0;
  upper = 300.0;
  step = 20.0;

  fahr = lower;

  // Heading
  printf("=====================\n");
  printf("Fahr to Celsius table\n");
  printf("=====================\n");

  printf("Fahr          Celsius\n");

  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%6.2f%15.2f\n", fahr, celsius);
    fahr = step + fahr;
  }
}
