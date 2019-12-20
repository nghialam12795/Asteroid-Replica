#include <iostream>
#include <SDL.h> // TODO(nghialam): find a way to include in all platform
using namespace std;

#include "constant.cpp"

// The window we will be rendering to
SDL_Window *window = nullptr;

// The surface contain by the window
SDL_Surface *screenSurface = nullptr;

bool init() {
  // Init flag
  bool success = true;

  // Init SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    cout << "SDL Failed to Initialize !!! \n SDL ERRORS: " << SDL_GetError() << endl;
    success = false;
  } else {
    window = SDL_CreateWindow("SDL !!!",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              Constant::kWidth,
                              Constant::kHeight,
                              SDL_WINDOW_SHOWN);
    SDL_SetWindowTitle(window, "Pixel Plot");
    if (window == nullptr) {
      cout << "Cannot create window !!! SDL ERRORS: " << SDL_GetError() << endl;
      success = false;
    } else {
      // Get window surface
      screenSurface = SDL_GetWindowSurface(window);
    }
  }

  return success;
}

void close() {
  // Destroy the window
  SDL_DestroyWindow(window);
  window = nullptr;

  // Quit SDL Subsystem
  SDL_Quit();
}

int main(int argc, char *argv[]) {
  // Start up SDL and create the window
  if (!init()) {
    cout << "Cannot create the window !!" << endl;
  }
  // Main loop flag
  bool quit = false;

  // Event Handler
  SDL_Event event;

  while (!quit) {
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
  }

  // Free resources and close SDL
  close();

  return 0;
}

