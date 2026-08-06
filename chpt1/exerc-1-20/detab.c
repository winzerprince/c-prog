// Exercise 1-20. Write a program detab that replaces tabs in the input with the
// proper number of blanks to space to the next tab stop. Assume a fixed set of
// tab stops, say every n columns. Should n be a variable or a symbolic
// parameter?
#include <stdio.h>
#define TAB 10 // space between tabs in number of characters

// NOTE: For this programs to work as expected, your terminal must be in raw
// mode (not cannonical mode) and have echo deisabled. Do this by running the
// following commands.
// WARNING: Use these commands with care, as it may be
// tricky to reanable echo without seeing what you are typing Disable
// 1. stty -icanon
// 2. stty -echo
// Re-enable
// 1. stty icanon
// 2. stty echo

int main() {
  int j, n = 0;
  char c;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      n = 0;
    } else if (c == '\t') {
      // Distance from previous tab stop
      j = n % TAB;

      // Fill remaining space till next tab stop with spaces
      for (int i = 0; i < (TAB - j); i++) {
        putchar(' ');
      }
      n = 0;
      continue;
    } else if (c == '\b') {
      n = n - 1;
    } else {
      n = n + 1;
    }
    putchar(c);
  }
  printf("%d", n);
}
