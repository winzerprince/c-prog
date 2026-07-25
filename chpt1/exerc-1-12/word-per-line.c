/* Exercise 1-12. Write a program that prints its input one word per line. */

#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
  char words[1024];
  int count, c;
  count = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n')
      break;
    if (c == ' ' || c == '\t') {
      c = '\n';
    }
    words[count] = c;
    count++;
  }

  for (int i = 0; i <= count; i++) {
    putchar(words[i]);
  }
}
