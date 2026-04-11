#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

  int c, i, n;
  i = n = 0;
  int state = OUT;
  int stream[255];

  // creates stream of the form [1,2,3,4,1,2,1,2,3,1,2,3,4,5] representing word
  // count
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      state = IN;
      continue;
    }
    if (state == IN) {
      i = 0;
      state = OUT;
    }

    i++;
    stream[n] = i;
    n++;
  }
  printf("\n");

  // Loop through stream[] to print out histogram
  for (int j = 0; j < n; j++) {
    if (stream[j] < stream[j + 1]) {
      printf("| ");
    } else {
      printf("|\n");
    }
  }
}
