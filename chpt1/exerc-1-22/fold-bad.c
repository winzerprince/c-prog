// Exercise 1-22. Write a program to ``fold'' long input lines into two or more
// shorter lines after the last non-blank character that occurs before the n-th
// column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the specified column.

// INPUT: A long line exceeding nth column
// OUTPUT: Multiple lines each no longer than n columns

#include <stdio.h>

#define N 10

int get_line(char s[], int lim);
void fold(char in[], char out[]);

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
  return i;
}

void fold(char in[], char out[]) {
  int i = 0;   // current word length
  int col = 0; // column position
  char temp[1024];
  int in_word = 1;
  while (1) {
    i = 0;

    // while in a word, increase word count and column count and copy word to
    // temp
    if (in_word) {
      while (in[col] != ' ') {
        col++;
        i++;
        in[col] = temp[i];
      }
      in_word = 0;
    }

    // Copy the word into out only if there's enough space otherwise go to next
    // line and copy word and reset col
    if (col < N) {
      for (int j = 0; j <= i; j++) {
        out[col - i + j] = temp[j];
      }
    } else {
      out[col - i] = '\n';
      for (int j = 0; j <= i; j++) {
        out[col - i + 1 + j] = temp[j];
      }
    }

    if (!in_word) {
      while (in[col] == ' ') {
        col++;
      }
      in_word = 1;
    }
  }
}
