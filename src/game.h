#ifndef ASTEROID_GAME_H_
#define ASTEROID_GAME_H_

#include "header.h"
#include "assets.h"

class Game {
 private:
  SDL_Window* window_ = nullptr;
  SDL_Renderer* renderer_ = nullptr;
  SDL_Event* main_event_ = nullptr;
  Assets* game_assets_ = nullptr;
  
 public:
  Game();
  ~Game();

  static Game* ME;
  static bool quit_game;

  void loop();
  void render(int &scroll_offset);
  void update();

  SDL_Renderer* get_renderer();
};

#endif //ASTEROID_GAME_H_
