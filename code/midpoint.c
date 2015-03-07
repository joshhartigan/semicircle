#include <stdio.h>

int * midpoint(int *p1, int *p2) {
  static int mp[2];
  mp[0] = (p1[0] + p2[0]) / 2;
  mp[1] = (p1[1] + p2[1]) / 2;

  return mp;
}

int main() {
  int point1[2] = { 13, 21 };
  int point2[2] = { 9, 25 };

  int * mp = midpoint(point1, point2);

  printf("midpoint of (%d, %d) and (%d, %d):"
         "\n(%d, %d)\n",
         point1[0], point1[1],
         point2[0], point2[1],
         mp[0], mp[1]);
}
