#include <stdio.h>
// Verifies expression getchar() != EOF is 0 for EOF and 1 otherwise

int main() {

  int c;

  while (c = getchar() != EOF) {
    printf("%d\n", c);
    getchar(); // consume the newline character from pressing enter
  }

  printf("%d\n", c);

  // Interesting behavior, ctrl+D which gives EOF leads to and infinite loop
  // probably cause all subsequent getchar() return EOF. EOF means the standard
  // input stream has reached its end and subsequent getchar() return EOF
  // without attempting to read
  /*
    while (1) {
      c = getchar() != EOF;
      printf("%d", c);
      getchar(); // consume the newline character from pressing enter
    }
  */
}
