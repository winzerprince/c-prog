// for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) s[i] = c;
// Exercise 2-2. Write a loop equivalent to the for loop above without using &&
// or ||.

#include <stdio.h>

int main() {

  int lim = 1024;
  char s[lim];
  char c;
  int i;

  for (i = 0; i < lim - 1; i++) {
    c = getchar();
    if (c == '\n') {
      break;
    } else if (c == EOF) {
      break;
    } else {
      s[i] = c;
    }
  }

  // Print values
  for (int j = 0; j <= i; j++) {
    printf("%c", s[j]);
  }
}
