#ifndef ASTEROID_GAME_H_
#define ASTEROID_GAME_H_

#include <sstream>

#include "header.h"
#include "assets.h"
#include "timer.h"
#include "ui/text.h"
#include "ent/player.h"
#include "controller.h"

class Game {
 private:
  SDL_Window* window_ = nullptr;
  SDL_Renderer* renderer_ = nullptr;
  SDL_Event* main_event_ = nullptr;
  Assets* game_assets_ = nullptr;
  Timer timer_;

  // Might be removed
  Text* fps_counter_ = nullptr;
  std::stringstream time_text;
  
 public:
  Game();
  ~Game();

  static Game* ME;
  static bool quit_game;
  static Player* player;
  static Controller* controller;

  void loop();
  void render(int &scroll_offset, int& frames, Timer &cap_timer);
  void update();

  SDL_Renderer* get_renderer();
};

#endif //ASTEROID_GAME_H_
