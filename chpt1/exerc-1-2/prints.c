#include <stdio.h>

int main() {
  printf("Hello, world\a");     // Terminal bell
  printf("Hello, world\b");     // Backspace
  printf("Hello, world\e");     // Escape character
  printf("Hello, world\f");     // Formfeed
  printf("Hello, world\r");     // Carriage return
  printf("Hello, world\t");     // Horizontal tab
  printf("Hello, world\u03A9"); // Unicode points
  printf("Hello, world\v");     // Vertical tab
  printf("Hello, world\x41");   // Hexadecimal digits i.e x41 = 65 = A
}
