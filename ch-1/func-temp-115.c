#include <stdio.h>

float fahrtocel(float a);

int main() {
  float lower, upper, step, current;
  lower = 0.0;
  upper = 300.0;
  step = 20.0;
  current = lower;

  printf("Fahrenheit to Celcius\n");
  printf("Fahrenheit\tCelcius\n");

  while (current <= upper) {
    float celcius = fahrtocel(current);

    printf("%10.2f%13.2f\n", current, celcius);
    current += step;
  }
}

float fahrtocel(float a) { return 5.0 / 9.0 * (a - 32); }
