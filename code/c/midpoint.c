#include <stdio.h>

typedef struct {
  float x;
  float y;
} point;

point midpoint(point p1, point p2) {
  point mp = {
    .x = (p1.x + p2.x) / 2,
    .y = (p1.y + p2.y) / 2
  };

  return mp;
}

int main() {
  point point1 = { .x = 13, .y = 21 };
  point point2 = { .x = 9,  .y = 25 };

  point mp = midpoint(point1, point2);

  printf("midpoint of (%g, %g) and (%g, %g):"
         "\n(%g, %g)\n",
         point1.x, point1.y,
         point2.x, point2.y,
         mp.x, mp.y);
}
