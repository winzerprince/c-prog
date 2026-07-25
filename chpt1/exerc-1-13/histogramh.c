// Exercise 1-13. Write a program to print a histogram of the lengths of words
// in its input. It is easy to draw the histogram with the bars horizontal; a
// vertical orientation is more challenging.

#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
  int lengths[1024];
  int index, state, c;
  index = state = 0;
  lengths[index] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      state = OUT;
      ++index;
      lengths[index] = 0;
      continue;
    } else if (state == OUT) {
      state = IN;
    }

    lengths[index] += 1;
  }

  for (int i = 0; i <= index; i++) {
    for (int k = 0; k < lengths[i]; k++) {
      printf("#");
    }
    printf("\n");
  }
}
