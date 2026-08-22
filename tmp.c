#include <ctype.h>
#include <stdio.h>

int main() {
  enum test { A = 1, B, C = 4, D };

  printf("%d %d", B, D);
}
