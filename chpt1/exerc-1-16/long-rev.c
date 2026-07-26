// Exercise 1-16. Revise the main routine of the longest-line program so it will
// correctly print the length of arbitrary long input lines, and as much as
// possible of the text.
//
#include <stdio.h>
// set low for testing so 10 character line will only display first 5 characters
#define MAXLINE 5

/* maximum input line length */
int get_line(char s[], int lim);

void copy(char to[], char from[]);

/* print the longest input line */

int main() {
  int len;               /* current line length */
  int max;               /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */
  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }

  if (max > 0) /* there was a line */
    printf("%s\nlength:%d", longest, max);
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
