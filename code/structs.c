#include <stdio.h>

// Immutability is generally good.
typedef const struct {
  char *name;
  int age;
  char *gender;
} person;

void introduce(person per) {
  printf("Hello, I am %s.\n", per.name);
  printf("I am a %d year-old %s person.\n", per.age, per.gender);
}

int main() {
  person me = { .name = "Josh", .age = 15, .gender = "Male" };
  introduce(me);

  person you = { .name = "a person", .age = 29, .gender = "Female" };
  introduce(you);
}
