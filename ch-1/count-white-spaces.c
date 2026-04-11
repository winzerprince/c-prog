#include <stdio.h>

int main() {
  int sc = 0;
  int val;

  while ((val = getchar()) != EOF) {
    if (val == ' ' || val == '\t' || val == '\n') {
      sc++;
    }
  }
  printf("%d", sc);
}
