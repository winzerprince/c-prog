// Exercise 1-13. Write a program to print a histogram of the lengths of words
// in its input. It is easy to draw the histogram with the bars horizontal; a
// vertical orientation is more challenging.

#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
  int lengths[1024];
  int index, state, tallest, c;
  index = state = tallest = 0;
  lengths[index] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (lengths[index] > tallest) {
        tallest = lengths[index];
      }
      state = OUT;
      ++index;
      lengths[index] = 0;
      continue;
    } else if (state == OUT) {
      state = IN;
    }

    lengths[index] += 1;
  }

  // printf("tallest: %d\nindex: %d\n", tallest, index);
  //  Print vertical histogram by using temp array derived from lengths for each
  //  layer of the vertical histogram
  //  for (int i = 0; i < index; i++) {
  //    printf("%d", lengths[i]);
  //  }

  for (int i = tallest; i >= 0; i--) {
    for (int j = 0; j < index; j++) {

      if ((lengths[j] - i) > 0) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
