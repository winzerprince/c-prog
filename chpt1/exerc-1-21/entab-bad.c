// Exercise 1-21. Write a program entab that replaces strings of blanks by the
// minimum number of tabs and blanks to achieve the same spacing. Use the same
// tab stops as for detab. When either a tab or a single blank would suffice to
// reach a tab stop, which should be given preference?

#include <stdio.h>
#define TAB 8
#define LIM 1024

int get_line(char *s, int lim);
void print_line(char *s, int lim);

int main() {
  char line[LIM];
  int len;
  char c;

  while (1) {
    len = get_line(line, LIM);
    int n = 0; // Number of non-white space characters
    int w = 0; // Number of white space characters
    int m = 0;
    if (len < 2) {
      break;
    }

    // When at a tab stop, convert all previous white spaces into groups of *
    // each worth length TAB characters otherwise print normal characters
    // except white spaces
    for (int i = 0; i < len; i++) {

      if ((n + w) == TAB || w > TAB) {
        // Prefer to print 1 white space instead of tab when 1 one space is left
        // to next tabstop
        if (w == 1) {
          printf(" ");
        } else if (w > 1 && w <= TAB) {

          printf("*");
        } else if (w > TAB) { // white spaces greater than TAB in number
          int j = w / TAB;    // Number of tabs
          int r = w % TAB;    // Remainder white spaces
          for (int k = j; k > 0; k--) {
            printf("*");
          }
          for (int k = r; k > 0; k--) {
            printf(" ");
          }
        }

        w = 0;
        n = 0;
      }
      // Don't print white spaces immediately
      if (line[i] == ' ') {
        w++;
      } else if (line[i] == '\t') {
        w = w + 8; // Tab is worth 8 white spaces in length
      } else {
        // Print all the white spaces before when a normal character is met
        for (int j = 0; j < w; j++) {
          printf(" ");
        }

        w = 0;
        n++;
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
