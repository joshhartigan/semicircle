#include <stdlib.h> // getenv, atoi
#include <stdio.h>  // printf

int main() {
  char *repeats_str = getenv("repeats");
  int repeats = repeats_str ? atoi(repeats_str) : 1;

  char *msg = getenv("msg");
  if (!msg) msg = "hello, world";

  for (int i = 0; i < repeats; i++) {
    printf("%s\n", msg);
  }
}
