#include <stdio.h>

// Counts the number of tabs, blnks and newline characters
int main() {
  long ws = 0;
  int c;

  // Will count '\n' passed in terminal as well, how can you avoid that, this is
  // cause input is buffered in canonical mode. Use stty -icanon to disable
  // canonical mode and stty icanon to reanable it to avoid using kernel buffer
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      ++ws;
    }
    printf("\n%ld\n", ws);
  }
}
