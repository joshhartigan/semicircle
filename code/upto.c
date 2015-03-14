#include <stdio.h>

#define UPTO(i, x) i < x; i++

int main() {
  int numbers[] = { 3, 6, 2, 9, 8, 1, 0, 4, 5 };
  int length = sizeof(numbers) / sizeof(int);

  for (int i = 0; UPTO(i, length)) {
    printf("%d ", numbers[i]);
  }
}
