#include <stdio.h>

/* 'int *x' means the function
 * takes a pointer to a certain
 * address, not the actual value
 * at that address. */
void times_two(int *x) {
  *x *= 2;
}

int main() {
  int num = 13;

  /* by prepending 'num' with an
   * ampersand, we supply the
   * function 'times_two' with the
   * address of 'num', not the value. */
  times_two(&num);
  printf("%d", num);
}
