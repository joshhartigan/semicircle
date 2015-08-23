#include <stdio.h>

int main() {
  long n = 600851475143;

  int i = 2;

  while (i * i < n) {
    while (n % i == 0) {
      n /= i;
    }
    i++;
  }

  printf("%ld\n", n);

}

