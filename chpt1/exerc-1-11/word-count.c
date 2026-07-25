// Exercise 1-11. How would you test the word count program? What kinds of input
// are most likely to uncover bugs if there are any?
//
// Answer
// Maybe characters like 😀, —, etc that are input using ctrl + shift + U get
// represent with more characters than you see. Also any white space characters
// not accounted for could be considered as part of a word you could test this
// by piping output form an echo command to this programming e.g
// echo "😀" | ./word-count
//
//
#include <stdio.h>
#define IN 1  /* inside a word */
#define OUT 0 /* outside a   word */

int main() {

  int c, nl, nw, nc, state;
  state = OUT;
  nl = nw = nc = 0;

  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}
