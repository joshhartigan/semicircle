#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ESCAPE_KEY 27

#define UP 'k'
#define DOWN 'j'
#define LEFT 'h'
#define RIGHT 'l'

#define CHOP 'c'
#define DEFAULT_DURABILITY 4

#define MAP_SIZE_X 40
#define MAP_SIZE_Y 20

#define WHITE          1
#define GREEN          2
#define YELLOW         3
#define ERROR_COLOR    4

char *grass_tiles[4] = { ".", "`", "'", "\"" };
char *tree_tile = "Y";

char *grass_types[8] = {
  "dry wheatgrass", "dry bluegrass", "dry ryegrass", "dry dead grass",
  "wet wheatgrass", "wet bluegrass", "wet ryegrass", "wet dead grass"
};

char *tree_types[8] = {
  "an apple tree, bearing no fruit.", "a birch tree",
  "an oak tree", "a small maple tree.", "an old maple tree",
  "a dying pear tree", "a pecan tree", "a willow tree"
};

char *map[MAP_SIZE_X][MAP_SIZE_Y];

typedef struct {
  int x;
  int y;
} coords;

typedef struct {
  coords position;
} person;

typedef struct {
  int logs;
  int axe;
} inventory;

person player = { { .x = 5, .y = 5 } };
inventory inv = {
  .logs = 0,
  .axe = DEFAULT_DURABILITY
};

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
  init_pair(ERROR_COLOR, COLOR_WHITE, COLOR_RED);
}

void generate_map() {
  for (int x = 0; x < MAP_SIZE_X; x++) {
    for (int y = 0; y < MAP_SIZE_Y; y++) {
      int type = (rand() % 101) + 1;

      int probability_tree = 3;

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

coords player_tile_adjacency(char *c) {
  int px = player.position.x;
  int py = player.position.y;

  char *up    = map[px][py - 1];
  char *down  = map[px][py + 1];
  char *left  = map[px - 1][py];
  char *right = map[px + 1][py];

  if (c == up) return (coords) { px, py - 1 };
  if (c == down) return (coords) { px, py + 1 };
  if (c == left) return (coords) { px - 1, py };
  if (c == right) return (coords) { px + 1, py };

  return (coords) { -1, -1 };
}

char *get_tile_info(int x, int y) {
  if (is_grass_tile(map[x][y])) {
    return grass_types[rand() % 8];
  }

  else if (map[x][y] == tree_tile) {
    return tree_types[rand() % 8];
  }

  else {
    return "ERROR! Non-descriptive tile";
  }
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

void draw_status() {
  int line = MAP_SIZE_Y + 3;

  color_set(WHITE, NULL);

  mvaddstr(line, 0, "Use hjkl to move,");
  line++;

  mvaddstr(line, 0, "Use c to chop down a tree,");
  line++;

  mvaddstr(line, 0, "Use escape to quit.");
  line++;

  mvaddstr(line, 0, "------------------------------");
  line++;

  // this line needs to be cleared because it can be of varying length.
  move(line, 0);
  clrtoeol();
  mvaddstr(line, 0, get_tile_info(player.position.x, player.position.y));
  line++;
}

void broken_status(char *toolname) {
  char message[80];
  snprintf(message, sizeof(message), "Your %s is broken.", toolname);
  color_set(ERROR_COLOR, NULL);
  mvaddstr(MAP_SIZE_Y + 1, 0, message);
}

void draw_inventory() {
  int min_x = MAP_SIZE_X + 1;
  int line = 0;
  int length = 20;

  mvaddstr(line, min_x, ",------------------,");
  line++;

  char logs[length];
  sprintf(logs, "| logs: %d          |", inv.logs);
  mvaddstr(line, min_x, logs);
  line++;

  char axe[length];
  sprintf(axe, "| axe: %d           |", inv.axe);
  mvaddstr(line, min_x, axe);
  line++;

  mvaddstr(line, min_x, "`------------------`");
  line++;

  refresh();
}

void chop_tree() {
  coords nearest = player_tile_adjacency(tree_tile);

  if (!(nearest.x == -1 && nearest.y == -1)) {
    if (inv.axe > 0) {
      map[nearest.x][nearest.y] = grass_tiles[rand() % 4];
      inv.logs++;
      inv.axe -= rand() % 2;
    }
  }

  if (inv.axe <= 0) {
    broken_status("axe");
  }
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

void handle_keypress(char key) {
  // movement
  if (key == UP || key == DOWN || key == LEFT || key == RIGHT) {
    coords movement = get_movement(player, key);
    player.position.x += movement.x;
    player.position.y += movement.y;
  }

  // chopping
  if (key == CHOP) {
    chop_tree();
  }
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
  draw_status();
  draw_inventory();

  char key = ' ';
  while (key != ESCAPE_KEY) {
    key = getch();

    handle_keypress(key);

    draw();
    draw_status();
    draw_inventory();
  }

  quit(window);
}
