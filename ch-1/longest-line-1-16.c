#include <stdio.h>

#define MAXLINE 10

int get_line(char store[], int limit);
void copy(char to[], char from[]);

int main() {

  int len, max;
  char lines[MAXLINE];
  char longest[MAXLINE];

  max = 0;

  while ((len = get_line(lines, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, lines);
    }
  }

  if (max > 0) {
    printf("%s", longest);
    printf("\n%d", max);
  }
}

// Get a line and read it into store[] then return line length
int get_line(char store[], int limit) {
  int c, i;
  i = 0;

  while ((c = getchar()) != '\n' && c != EOF) {

    if (i < limit - 1) {
      store[i] = c;
    }
    i++;
  }
  if (c == '\n') {
    store[i] = c;
    i++;
  }
  store[i] = '\0';
  return i;
}

// Copy from into to assuming to is big enough
void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0') {
    i++;
  }
}
