#include <stdio.h>

int main() {

  int a = 1,
      b = 1,
      c = 1,
      total = 0;

  while (c <= 4000000) {
    if (c % 2 == 0) {
      total += c;
    }
    c = a + b;
    a = b;
    b = c;
  }

  printf("%d\n", total);
}

