#include <stdio.h>

typedef struct {
  char *name;
  int age;
  char *gender;
  char *description;
} person;

void introduce(person per) {
  printf("Hello, I am %s.\n", per.name);
  printf("I am a %d year-old %s person.\n", per.age, per.gender);
  printf("I am %s.\n", per.description);
}

void birthday(person *per) {
  printf("Happy birthday, %s!\n", per->name);
  per->age += 1;
}

int main() {
  person me = { .name = "Josh", .age = 15, .gender = "Male",
    .description = "the creator of all living and non-living things" };
  introduce(me);

  printf("\n");

  person you = { .name = "a person", .age = 29, .gender = "Female",
    .description = "the most intelligent person ever" };
  introduce(you);

  printf("\n");

  printf("%s is %d years old.\n", me.name, me.age);
  birthday(&me);
  printf("%s is now %d years old.\n", me.name, me.age);
}
