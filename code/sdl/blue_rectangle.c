#include "SDL.h"

int main () {

    SDL_Window* win;
    win = SDL_CreateWindow("drawing",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      500,
      500,
      SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer;
    renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // clear window
    SDL_RenderClear(renderer);

    SDL_Rect rect = { 210, 210, 40, 40 }; // x, y, width, height

    SDL_SetRenderDrawColor(renderer, 0, 17, 87, 240);

    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);

    SDL_Delay(2000); // 2 seconds

    SDL_DestroyWindow(win);
    SDL_Quit();

}
