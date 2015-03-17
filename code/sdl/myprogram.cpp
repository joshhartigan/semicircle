// include functions and types from
// sdl library
#include "SDL/SDL.h"
#include <string>

// screen attributes
const int kScreenWidth = 640;
const int kScreenHeight = 480;
const int kScreenBPP = 32; // bits per pixel (i.e. 32-bit color)

// surfaces to be used
SDL_Surface *image = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

SDL_Surface *LoadImage(std::string filename) {
  // temp storage for loaded image
  SDL_Surface *loadedimage = NULL;
  // optimized image to be used
  SDL_Surface *optimizedimage = NULL;

  // load image
  loadedimage = SDL_LoadBMP(filename.c_str());
  // check for loading errors
  if (loadedimage != NULL) {
    optimizedimage = SDL_DisplayFormat(loadedimage);
    // free old image
    SDL_FreeSurface(loadedimage);
  }

  return optimizedimage;
}

void ApplySurface(int x, int y, SDL_Surface *source, SDL_Surface *destination) {
  // temporary rectangle to hold offsets
  SDL_Rect offset;
  // give offsets to rectangle
  offset.x = x;
  offset.y = y;

  // blit surface
  SDL_BlitSurface(source, NULL, destination, &offset);
}

int main(int argc, char* args[]) {
  // init sdl subsystems
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
    return 1;
  }
  // set up screen
  screen = SDL_SetVideoMode(kScreenWidth, kScreenHeight, kScreenBPP, SDL_SWSURFACE);
  // check for screen setup errors
  if (screen == NULL) {
    return 1;
  }
  // set window title
  SDL_WM_SetCaption("my program", NULL);

  // load image
  image = LoadImage("hello.bmp");
  background = LoadImage("background.bmp");
  // apply background
  ApplySurface(0, 0, background, screen);
  ApplySurface(320, 0, background, screen);
  ApplySurface(0, 240, background, screen);
  ApplySurface(320, 240, background, screen);
  // apply image
  ApplySurface(180, 140, image, screen);

  // update screen
  if (SDL_Flip(screen) == -1) {
    return 1;
  }

  SDL_Delay(2000);

  // free surfaces and quit
  SDL_FreeSurface(image);
  SDL_FreeSurface(background);
  SDL_Quit();

  return 0;
}
