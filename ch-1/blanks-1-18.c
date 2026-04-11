#include <stdio.h>

#define MAXLINE 1000
#define MAXROWS 1000

int get_line(char store[], int limit);
void copy(char to[], char from[]);

int main() {

  int len, max, r;
  char lines[MAXLINE];
  char longest[MAXLINE];
  char rows[MAXROWS][MAXLINE];

  r = max = 0;

  while ((len = get_line(lines, MAXLINE)) > 0) {
    if (len > 1) { // ingore blank lines with one character only ie \n
      max = len;
      copy(rows[r], lines); // copy line(character array) to row[r]
      r++;
    }
  }

  if (max > 0) {

    for (int i = 0; i < r; i++) {
      printf("%d. %s\n", i, rows[i]);
    }
  }
} // Get a line and read it into store[] then return line length
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

    while (store[i - 1] == ' ' ||
           store[i - 1] == '\t') { // loop backwards past blanks and tabs
      i--;
    }

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
