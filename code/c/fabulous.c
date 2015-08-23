#include <stdio.h>
#include <unistd.h>
#include <curses.h>

void init_colors() {
  init_pair(1,  COLOR_RED,     COLOR_BLACK);
  init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
  init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
  init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
  init_pair(5,  COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6,  COLOR_CYAN,    COLOR_BLACK);
  init_pair(7,  COLOR_BLUE,    COLOR_WHITE);
  init_pair(8,  COLOR_WHITE,   COLOR_RED);
  init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
  init_pair(10, COLOR_BLUE,    COLOR_YELLOW);
  init_pair(11, COLOR_WHITE,   COLOR_BLUE);
  init_pair(12, COLOR_WHITE,   COLOR_MAGENTA);
  init_pair(13, COLOR_BLACK,   COLOR_CYAN);
}

int main() {
  WINDOW *window;

  if ((window = initscr()) == NULL) {
    fprintf(stderr, "error initialising curses.\n");
    return 1;
  }

  start_color();

  if (has_colors() && COLOR_PAIRS >= 13) {
    init_colors();
    for (int i = 0; i < 13; i++) {
      color_set(i, NULL);
      mvaddstr(6 + i, 32, "rainbow");
      refresh();
      usleep(100 * 1000);
      clear();
    }
  }

  getch();

  delwin(window);
  endwin();
  refresh();
}

