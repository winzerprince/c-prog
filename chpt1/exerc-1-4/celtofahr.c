#include <stdio.h>
// Prints temperature converstion table from celsius to fahrenheit from -20 to
// 280

int main() {
  float lower, upper, step;
  float celsius, fahr;

  lower = -20.0;
  upper = 280.0;
  step = 20.0;

  celsius = lower;

  printf("=====================\n");
  printf("Celcius to fahr table\n");
  printf("=====================\n");
  printf("Celcius          Fahr\n");

  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * (celsius + 32);
    printf("%6.2f%15.2f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
