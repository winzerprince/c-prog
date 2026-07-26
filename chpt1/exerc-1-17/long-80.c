// Exercise 1-17. Write a program to print all input lines that are longer than
// 80 characters.

#include <stdio.h>

#define MAXLINE 1000
#define BOUND 80 /* set to lower value like 8 for easier testing */

int get_line(char s[], int lim);

void copy(char to[], char from[]);

/* print all input lines greater than 80 characters */

int main() {
  int len;                      /* current line length */
  char line[MAXLINE];           /* current input line */
  char printable[MAXLINE * 64]; /* Stores characters from comining all lines >
                                   BOUND in length */
  int printable_cursor = 0;     /* Keep track of position in printable array */
  int counts[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > BOUND) {
      for (int i = 0; i <= len; i++) {
        printable[printable_cursor] = line[i];
        ++printable_cursor;
      }
    }
  }

  for (int i = 0; i <= printable_cursor; i++) {
    printf("%c", printable[i]);
  }

  return 0;
}

/* getline: read a line into s, return length regardless of limit*/
int get_line(char s[], int lim) {
  int c, i;
  i = 0;
  while ((c = getchar()) != EOF && c != '\n') {
    if (i < (lim - 1)) {
      s[i] = c;
    }
    ++i;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
