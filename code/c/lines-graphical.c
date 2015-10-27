// this code is quite messy

#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int WIDTH = 300;
const int HEIGHT = 300;

SDL_Window *win;
SDL_Renderer *ren;

bool keys[322];
bool running = false;

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  Point from;
  Point to;
} Line;

Line main_line;

void handle_arguments(int argc, char **argv);
void game_loop();
void blank_screen();
void draw_point(Point pt);
void put_line(Line ln);
void init_input();
void update_keys();
void handle_keys();

int main(int argc, char **argv) {
  handle_arguments(argc, argv);
  init_input();

  win = SDL_CreateWindow(
      "line drawing",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, // center the window
      WIDTH, HEIGHT,
      SDL_WINDOW_SHOWN);
  ren = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);

  running = true;
  game_loop();
  SDL_DestroyWindow(win);
  SDL_Quit();
}

void handle_arguments(int argc, char **argv) {
  if (argc < 5) {
    fprintf(stderr, "error: too few arguments! (need x1, y1, x2, y2)\n");
    exit(1);
  }

  if (argc > 5) {
    fprintf(stderr, "error: too many arguments! (need x1, y1, x2, y2)\n");
    exit(1);
  }

  // else
  main_line.from.x = atoi(argv[1]);
  main_line.from.y = atoi(argv[2]);
  main_line.to.x = atoi(argv[3]);
  main_line.to.y = atoi(argv[4]);
}

void game_loop() {
  while (running) {
    // update things
    update_keys();
    handle_keys();
    // draw things
    blank_screen();
    put_line(main_line);
    // apply drawing
    SDL_RenderPresent(ren);
  }
}

void blank_screen() {
  SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
  SDL_RenderClear(ren);
}

void draw_point(Point pt) {
  SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
  SDL_RenderDrawPoint(ren, pt.x, pt.y);
}

void put_line(Line ln) {
  int delta_x = abs(ln.to.x - ln.from.x);
  int sx = ln.from.x < ln.to.x ? 1 : -1;

  int delta_y = abs(ln.to.y - ln.from.y);
  int sy = ln.from.y < ln.to.y ? 1 : -1;

  int err = (delta_x > delta_y ? delta_x : -delta_y) / 2;
  int e2;

  while (1) {
    Point here = { ln.from.x, ln.from.y };
    draw_point(here);

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

void init_input() {
  for (int i = 0 ; i < 322; i++) {
    keys[i] = false;
  }
}

void update_keys() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        if (event.key.keysym.sym < 322) {
          keys[event.key.keysym.sym] = true;
        }
        break;
      case SDL_KEYUP:
        if (event.key.keysym.sym < 322) {
          keys[event.key.keysym.sym] = false;
        }
        break;
      default:
        break;
    }
  }
}

void handle_keys() {
  if (keys[SDLK_q]) {
    running = false;
  }
}
