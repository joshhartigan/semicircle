#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ESCAPE_KEY 27

#define UP 'k'
#define DOWN 'j'
#define LEFT 'h'
#define RIGHT 'l'

#define MAP_SIZE_X 40
#define MAP_SIZE_Y 20

#define WHITE  1
#define GREEN  2
#define YELLOW 3

char *grass_tiles[4] = { ".", "`", "'", "\"" };
char *tree_tile = "#";

char *map[MAP_SIZE_X][MAP_SIZE_Y];

typedef struct {
  int x;
  int y;
} coords;

typedef struct {
  coords position;
} person;

person player = { { .x = 5, .y = 5 } };

WINDOW *window;

void quit(WINDOW *window) {
  delwin(window);
  endwin();
  refresh();
}

void init_colors() {
  init_pair(WHITE,  COLOR_WHITE,  COLOR_BLACK);
  init_pair(GREEN,  COLOR_GREEN,  COLOR_BLACK);
  init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
}

void generate_map() {

  for (int x = 0; x < MAP_SIZE_X; x++) {
    for (int y = 0; y < MAP_SIZE_Y; y++) {
      int type = (rand() % 101) + 1;

      int probability_tree = 2;

      if (type < probability_tree) {
        map[x][y] = tree_tile;
      }

      // TODO: check for other tiletypes ...

      else { // everything that isn't special is just grass.
        map[x][y] = grass_tiles[rand() % 4];
      }
    }
  }
}

bool is_grass_tile(char *c) {
  for (int i = 0; i < 4; i++) {
    if (grass_tiles[i] == c) {
      return true;
    }
  }

  return false;
}

void draw() {
  for (int x = 0; x < MAP_SIZE_X; x++) {
    for (int y = 0; y < MAP_SIZE_Y; y++) {
      if (x == player.position.x && y == player.position.y) {
        color_set(WHITE, NULL);
        mvaddstr(y, x, "@");
        refresh();
      }

      // TODO: draw other entities ...

      else { // there is a tile at the coordinate.
        if (map[x][y] == tree_tile) {
          color_set(YELLOW, NULL);
        }

        if (is_grass_tile(map[x][y])) {
          color_set(GREEN, NULL);
        }

        mvaddstr(y, x, map[x][y]);
        refresh();
      }
    }
  }

  refresh();
}

coords get_movement(person p, char key) {
  int diff_x = 0;
  int diff_y = 0;

  if (key == UP && p.position.y > 0) {
    diff_y = -1;
  }

  else if (key == DOWN && p.position.y < MAP_SIZE_Y - 1) {
    diff_y = 1;
  }

  else if (key == LEFT && p.position.x > 0) {
    diff_x = -1;
  }

  else if (key == RIGHT && p.position.x < MAP_SIZE_X - 1) {
    diff_x = 1;
  }

  return (coords) { diff_x, diff_y };
}

int main() {
  srand(time(NULL));

  window = initscr();

  if (window == NULL) {
    fprintf(stderr, "error initialising curses.\n");
    return 1;
  }

  start_color();

  if (has_colors() && COLOR_PAIRS >= 13) {
    init_colors();
  }


  curs_set(0); // hide the cursor
  noecho(); // do not show characters when they've been typed

  generate_map();
  draw();

  char key = ' ';
  while (key != ESCAPE_KEY) {
    key = getch();

    coords movement = get_movement(player, key);
    player.position.x += movement.x;
    player.position.y += movement.y;

    draw();
  }

  quit(window);
}
