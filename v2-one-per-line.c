#include <stdio.h>

#define IN 0
#define OUT 1
int main() {
  int c;
  int state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      state = IN;
      continue;
    }
    if (state == IN) {
      state = OUT;
      putchar('\n');
    }
    putchar(c);
  }
}
