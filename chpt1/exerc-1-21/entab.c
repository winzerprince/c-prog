// Exercise 1-21. Write a program entab that replaces strings of blanks by the
// minimum number of tabs and blanks to achieve the same spacing. Use the same
// tab stops as for detab. When either a tab or a single blank would suffice to
// reach a tab stop, which should be given preference?

#include <stdio.h>
#define TAB 8

int get_line(char *s, int lim);
void detab(char *s, int size);

int main() {}

int get_line(char *s, int lim) {
  char c;
  int i = 0;
  while ((c = getchar()) != EOF && c != '\n') {
    if (i < lim - 1) {
      s[i] = c;
    }
    i++;
  }

  if (c == '\n') {
    s[i] = '\n';
    i++;
  }
  s[i] = '\0';
  return i + 2;
}

void detab(char *s, int size) {}
