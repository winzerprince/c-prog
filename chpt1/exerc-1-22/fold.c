// Exercise 1-22. Write a program to ``fold'' long input lines into two or more
// shorter lines after the last non-blank character that occurs before the n-th
// column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the specified column.

#include <stdio.h>
#define LIM 1024

int get_line(char s[], int lim);
void fold(char in[], char out[]);
void print_line(char s[]);

int main() {
  char line[LIM];
  char folded[LIM];

  int size = get_line(line, LIM);

  fold(line, folded);

  print_line(folded);
}

int get_line(char s[], int lim) {
  char c;
  int i = 0;
  while ((c = getchar()) != EOF && c != '\n') {

    if (i < lim - 1) {
      s[i] = c;
      i++;
    }
  }
  if (c == '\n') {
    s[i] = '\n';
    i++;
  }
  s[i] = '\0';
  return i;
}

void fold(char in[], char out[]) {
  int i = 0;
  while (in[i] != '\0') {
    out[i] = in[i];
    i++;
  }
}
void print_line(char s[]) {
  int i = 0;
  while (s[i] != '\0') {
    printf("%c", s[i]);
    i++;
  }
}
