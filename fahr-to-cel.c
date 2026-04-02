#include <stdio.h>

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  step = 20;
  upper = 300;
  fahr = lower;

  printf("Fahrenheit to Celcius\n\n");
  printf("Fahrenheit\tCelcius\n");
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%10.2f%13.2f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
