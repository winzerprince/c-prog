// Exercise 1-14. Write a program to print a histogram of the frequencies of
// different characters in its input

#include <stdio.h>

#define MAX 1000

void add_char(char token, char tokens[]);
void add_count(char token, char tokens[], int token_count[]);
int get_input(char input[]);
int in_array(char token, char tokens[]);

// Free  positiion just after the last character in the character array
int token_cursor = 0;
char input[MAX], tokens[MAX];
int token_count[MAX];
int input_size = 0;
void histogram(char *tokens, int *token_count);

int main(void) {

  // Get user input
  input_size = get_input(input);

  // Process input
  // loop through input, check if token exists in tokens, add it if it doesnt,
  // increment its value in token_count, move on to the next until
  // the end of input
  for (int i = 0; i <= input_size; i++) {
    char token = input[i];

    if (in_array(token, tokens) == 0) {

      add_char(token, tokens);
    }

    add_count(token, tokens, token_count);
  }

  // Display histogram
  // display newline using  '\\n' and tab as '\\t'
  histogram(tokens, token_count);
}

// Appends a character to the character array and moves char_cursor forward by 1
// position
void add_char(char token, char tokens[]) {
  tokens[token_cursor] = token;
  token_cursor++;
}

// Increment number in index of token_count list corresponding to the token by
// one, assumes token exists in token
void add_count(char token, char tokens[], int token_count[]) {
  int i;
  for (i = token_cursor; i >= 0; i--) {
    if (tokens[i] == token) {
      break;
    }
  }

  token_count[i]++;
}

// Adds input characters to input array until EOF, returns index of last
// character in the array
int get_input(char input[]) {
  int i = 0;
  char c;
  while ((c = getchar()) != EOF) {
    input[i] = c;
    i++;
  }
  return i;
}

// Returns 1 or 0 if a token exists in tokens array or not repectively
int in_array(char token, char tokens[]) {
  int status = 0;

  for (int i = token_cursor; i >= 0; i--) {
    if (tokens[i] == token) {
      status = 1;
    }
  }
  return status;
}

void histogram(char *tokens, int *token_count) {
  for (int i = 0; i < token_cursor; i++) {
    if (tokens[i] == '\n') {

      printf("\\n: ");
    } else if (tokens[i] == '\t') {

      printf("\\t: ");
    } else {

      printf(" %c: ", tokens[i]);
    }

    for (int j = 1; j <= token_count[i]; j++) {

      printf("#");
    }
    printf("\n");
  }
}
