// Exercise 2-3. Write a function htoi(s), which converts a string of
// hexadecimal digits (including an optional 0x or 0X) into its equivalent
// integer value. The allowable digits are 0 through 9, a through f, and A
// through F.

// 0-9 = 48 - 57
// A-Z = 65-90
// a-z = 97-172

#include <stdio.h>

int to_hex(char *s, int lim, int num[]);
int get_string(char *s, int lim);

int main() {
  int lim = 1024;
  char s[lim];
  int num[lim];

  int count = get_string(s, lim);
  // printf("\n%s", s);
  //
  // int digit_count = to_hex(s, count, num);
  //
  // for (int i = 0; i < digit_count; i++) {
  //   printf("%d ", num[i]);
  // }
  //
  int hex = to_hex(s, count, num);
  printf("%d", hex);
}

// Converts hex string to an integer, expects digits to be large enough
int to_hex(char *s, int lim, int digits[]) {
  char c;
  int j = 0;   // pos in character array s
  int i = 0;   // pos in digits
  int sum = 0; // sum of product of digits and their place values
  int has_0x = 0;

  // If string starts with '0x' or '0X', skip those
  if (s[j] == '0' && (s[j + 1] == 'x' || s[j + 1] == 'X')) {
    j = 2;
    has_0x = 1;
  }

  // Loop through the characters to the last excluding '\n'
  for (; j < lim - 1; j++) {
    c = s[j];

    if (c >= 48 && c <= 57) { // Ascii range 0-9
      digits[i] = c - 48;

    } else if (c >= 65 && c <= 70) { // Ascii range A-F

      //  A is Ascii value 65, 65  - 55 is 10 which is equivalent to converting
      //  hex value A to 10
      digits[i] = c - 55;

    } else if (c >= 97 && c <= 102) { // Ascii range a-f

      // a is Ascii value 97, 97-87 = 10, equivalent to converting hex a to 10
      digits[i] = c - 87;

    } else {
      digits[i] = 0;
    }
    i++;
  }

  printf("\nj: %d\n", j);
  // Multiply each digit by its place value and add to the sum
  if (has_0x) {
    j -= 2;
  }
  int pv_num = 0;
  int pv = j - 1;

  for (int i = 0; i <= j; i++) {
    pv_num = 1;

    for (int k = 0; k < pv; k++) {
      pv_num *= 16;
    }

    sum += digits[i] * pv_num;
    pv--;
  }

  return sum;
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
