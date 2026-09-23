// PENDING
// Exercise 2-5. Write the function any(s1,s2), which returns the first location
// in a string s1 where any character from the string s2 occurs, or -1 if s1
// contains no characters from s2. (The standard library function strpbrk does
// the same job but returns a pointer to the location.)
//
// Example
// s1 = "bones"
// s2 = "oes"
//
// any(s1,s2) returns 1
//
// Approach 1:
// For each character in s1, check if it's in s2, return index of character if
// true reuturn -1 at end.

// Functions
// getline(): get input for characters from user. in(array to store values,
// limit as size of array), out(void) any(s1,s2): implementation of any, in(s1,
// s2) , out(int)

#include <stdio.h>
#define LIM 1024

int get_line(char *s, int lim);
int any(char *s1, char *s2);

int main() {

  // Test get_line
  // char line[lim];
  //
  // int num = get_line(line, lim);
  //
  // for (int i = 0; i < num; i++) {
  //   printf("%c", line[i]);
  // }

  // // Test any
  // char *s1 = "bones\0";
  // char *s2 = "ne\0";
  //
  // int num = any(s1, s2);
  // printf("%d", num);
  //

  char s1[LIM];
  char s2[LIM];

  printf("Please enter s1: ");
  get_line(s1, LIM);

  printf("Please enter s2: ");
  get_line(s2, LIM);

  int num = any(s1, s2);
  printf("%d", num);
}

// Loop throught the characters of s1 and s2 untile you find a match & return
// its position in s1
int any(char *s1, char *s2) {
  int i = 0;
  int j;

  // watch out for '\n' since it is part of user input
  while (s1[i] != '\0' && s1[i] != '\n') {

    j = 0;
    while (s2[j] != '\0' && s2[j] != '\n') {
      // Debug the loop
      // printf("s1[%d] = %c s2[%d] = %c\n", i, s1[i], j, s2[j]);
      if (s1[i] == s2[j]) {
        return i;
      }
      j++;
    }

    i++;
  }
  return -1;
}

int get_line(char *s, int lim) {
  char c;
  int i = 0;

  while ((c = getchar()) != EOF && c != '\n') {

    if (i == lim - 1) {
      break;
    }

    s[i] = c;
    i++;
  }

  if (c == '\n') {
    s[i] = '\n';
    i++;
  }

  s[i] = '\0';
  i++;
  return i;
}
