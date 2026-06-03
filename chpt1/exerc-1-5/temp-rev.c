#include <stdio.h>
// Prints temperature conversions from fahrenheit to celsius from 300 to 0
int main() {

  float lower, upper, step;
  float fahr, celsius;

  lower = 0.0;
  upper = 300.0;
  step = 20.0;

  fahr = upper;

  // Heading
  printf("=====================\n");
  printf("Fahr to Celsius table\n");
  printf("=====================\n");

  printf("Fahr          Celsius\n");

  while (fahr >= lower) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%6.2f%15.2f\n", fahr, celsius);
    fahr = fahr - step;
  }
}
