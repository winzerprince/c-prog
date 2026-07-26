// Exercise 1-18. Write a program to remove trailing blanks and tabs from each
// line of input, and to delete entirely blank lines.

#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int clean_line(char s[], int len);
void copy(char to[], char from[]);

/* print all input lines greater than 80 characters */

int main() {
  int len;            /* current line length */
  char line[MAXLINE]; /* current input line */
  char all_lines[MAXLINE * 64];
  int cursor = 0;

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len < 2) /* eliminate lines with only '\n' making them blank lines */
      continue;
    len = clean_line(line, len);

    for (int i = 0; i <= len; i++) {
      all_lines[cursor] = line[i];
      ++cursor;
    }
  }

  for (int i = 0; i <= cursor; i++) {
    printf("%c", all_lines[i]);
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

int clean_line(char s[], int len) {

  int deduct = 0;
  for (int i = len; i >= 0; i--) {

    if (s[i] == '\n' || s[i] == ' ' || s[i] == '\t' || s[i] == '\0') {
      ++deduct;

    } else {
      s[i + 1] = '\n';
      s[i + 2] = '\0';

      break;
    }
  }
  return (len - deduct + 2);
}
