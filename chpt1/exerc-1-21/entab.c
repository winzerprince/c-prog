// Exercise 1-21. Write a program entab that replaces strings of blanks by the
// minimum number of tabs and blanks to achieve the same spacing. Use the same
// tab stops as for detab. When either a tab or a single blank would suffice to
// reach a tab stop, which should be given preference?

/* | | | | | | | | T | | | | | | | T | | | | |
 *  0 1 2 3 4 5 6 7 8 9 A B C D E F G H I J K L
 *
 * T is a tab stop appearing after every 8 characters for TAB=8
 * Approach inspired by Faisal Saadatmand  implementation of entab:
 * https://github.com/fsaadatmand/The-C-Programming-Language/blob/master/chpater01%2F1-21.c
 *
 * NOTE: tabs are represented by * in this program for easy recognition
 */

#include <stdio.h>
#define TAB 8 // Number of characters between tabstop
#define LIM 1024

int get_line(char *s, int lim);
void print_line(char *s, int lim);

int main() {
  char line[LIM];
  int len;
  char c;
  int nwhite = 0;
  int ntabs = 0;

  while (1) {
    len = get_line(line, LIM);

    for (int i = 0; line[i] != '\0'; i++) {
      // Whenever ' ' is encountered, start counting white spaces and every time
      // tab stop is encountered "compress" previous white spaces into a tab(*)
      // continue till no more white spaces then print tabs and white spaces
      // counted
      if (line[i] == ' ') {
        for (; line[i] == ' '; i++) {
          if ((i + 1) % TAB == 0) {
            ++ntabs;
            nwhite = 0;
          } else {
            nwhite++;
          }
        }

        --i; // Reposition a step back after looping through tabs and white
             // spaces
        // Print tabs then blanks NOTE: Each tab is represented here by *, '\t'
        // can be used alternatively
        while (ntabs > 0) {
          printf("*");
          ntabs--;
        }
        while (nwhite > 0) {
          printf(" ");
          nwhite--;
        }
      } else {
        printf("%c", line[i]);
      }
    }
  }
}

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

// position is divisible by TAB

void print_line(char *s, int lim) {
  int i = 0;
  while (s[i] != '\0') {
    printf("%c", s[i]);
    i++;
  }
}
