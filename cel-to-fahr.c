#include <stdio.h>

int main() {
  float celcius, fahr;
  float lower, upper, step;

  lower = 0.0;
  step = 20.0;
  upper = 300.0;

  printf("Celcius to Fahrenheit\n");
  printf("Celcius\tFahrenheit\n");

  while (celcius <= 300) {
    fahr = 9.0 / 5.0 * (celcius + 32);
    printf("%7.2f%18.2f\n", celcius, fahr);
    celcius = celcius + step;
  }
}
