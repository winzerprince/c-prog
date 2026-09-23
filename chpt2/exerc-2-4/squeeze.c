// PENDING
// Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes
// each character in s1 that matches any character in the string s2.
#include <stdio.h>
#define LIM 1024

int get_string(char *s, int lim);

int main() {
  char s1[LIM];
  char s2[LIM];

  printf("Enter string 1:\n");

  int count1 = get_string(s1, LIM);
  printf("Enter string 2:\n");
  int count2 = get_string(s2, LIM);

  printf("string1: %s\n", s1);

  printf("string2: %s", s2);
}

int get_string(char *s, int lim) {
  char c;
  int i = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
    if (i < lim - 1) {
      s[i] = c;
      i++;
    } else {
      break;
    }
  }

  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}
