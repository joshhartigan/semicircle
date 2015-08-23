#include <stdio.h>

int main() {

  int total = 0;

  for (int i = 1; i < 1000; ++i) {
    if (i % 3 == 0 || i % 5 == 0) {
      total += i;
    }
  }

  printf("%d\n", total);

}

