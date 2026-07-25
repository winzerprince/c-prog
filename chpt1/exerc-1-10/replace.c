// Exercise 1-10. Write a program to copy its input to its output, replacing
// each tab by \t, each backspace by \b, and each backslash by \\. This makes
// tabs and backspaces visible in an unambiguous way.

#include <stdio.h>
// For this backspace to be registerd as input, you terminal should not be in
// canonical mode, to disable it, type stty -icanon , to enable it type stty
// icanon, you may also get '^?' from the terminal driver
// You can also run stty -echo to disable echo and hide your inputmaking the
// program furnction as intented and type stty echo to renable it
int main() {

  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      printf("\\t");
    } else if (c == 127 || c == '\b') { // Backspace is ASCII character 127
      printf("\\b");

    } else if (c == '\\') {
      printf("\\\\");
    } else {
      printf("%c", c);
    }
  }
}
