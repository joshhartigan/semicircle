#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRAPH_SIZE 10

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  point from;
  point to;
} line;

bool vertical(line ln) {
  return ln.from.x == ln.to.x;
}

void put_line(line ln, char gr[GRAPH_SIZE][GRAPH_SIZE]) {
  /* Place the line `ln` on the graph `gr`. */
  int delta_x = abs(ln.to.x - ln.from.x);
  int sx = ln.from.x < ln.to.x ? 1 : -1;

  int delta_y = abs(ln.to.y - ln.from.y);
  int sy = ln.from.y < ln.to.y ? 1 : -1;

  int err = (delta_x > delta_y ? delta_x : -delta_y) / 2;
  int e2;

  while (1) {
    gr[ln.from.x][ln.from.y] = 'x';

    if (ln.from.x == ln.to.x && ln.from.y == ln.to.y) {
      break;
    }

    e2 = err;

    if (e2 > -delta_x) {
      err -= delta_y;
      ln.from.x += sx;
    }

    if (e2 < delta_y) {
      err += delta_x;
      ln.from.y += sy;
    }
  }
}

void print_graph(char gr[GRAPH_SIZE][GRAPH_SIZE]) {
  /* Display the entirety of graph `gr`. */
  for (int x = 0; x < GRAPH_SIZE; x++) {
    for (int y = 0; y < GRAPH_SIZE; y++) {
      printf("%c ", gr[x][y]);
    }

    printf("\n");
  }
}

int main() {
  line ln = { { 0, 0 }, { 7, 9 } };
  char graph[GRAPH_SIZE][GRAPH_SIZE];

  for (int x = 0; x < GRAPH_SIZE; x++) {
    for (int y = 0; y < GRAPH_SIZE; y++) {
      graph[x][y] = '.';
    }
  }

  put_line(ln, graph);
  print_graph(graph);
}
