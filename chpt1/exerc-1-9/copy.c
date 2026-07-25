// Exercise 1-9. Write a program to copy its input to its output, replacing each
// string of one or more blanks by a single blank.

#include <stdio.h>

int main() {
  int c;
  int blanked = 0; // Used to remember if there was a blank in the previous loop

  while ((c = getchar()) != EOF) {
    if (c == ' ' && blanked == 0) {

      printf(" ");
      blanked = 1;
    } else {
      if (blanked == 1 && c == ' ') {
        ;
      } else {

        printf("%c", c);
        blanked = 0;
      }
    }
  }
}
