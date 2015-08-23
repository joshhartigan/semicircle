#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
  printf("Enter input: ");

  char str[MAX_SIZE + 1]; // up to MAX_SIZE chars + '\0'
  fgets(str, MAX_SIZE + 1, stdin);

  for (int i = strlen(str) - 1; i >= 0; i--) {
    if (str[i] == '\n')
      continue; // don't write newline
    else
      putchar(str[i]);
  }

  printf("\n");
}
