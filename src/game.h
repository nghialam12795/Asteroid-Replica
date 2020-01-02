#ifndef ASTEROID_GAME_H_
#define ASTEROID_GAME_H_

#include <sstream>

#include "header.h"
#include "assets.h"
#include "audio.h"
#include "timer.h"
#include "ui/text.h"
#include "ent/player.h"
#include "ent/fighter.h"
#include "controller.h"

class Game {
 private:
  SDL_Window* window_ = nullptr;
  SDL_Renderer* renderer_ = nullptr;
  SDL_Event* main_event_ = nullptr;
  Assets* game_assets_ = nullptr;
  Audio* game_audio_ = nullptr;
  Timer timer_;

  // Might be removed
  int enemy_spawn_  = 0;  // need to use it cause timer is broken with SDL_Delay
  int obstcl_spawn_ = 0;  // need to use it cause timer is broken with SDL_Delay
                          // TODO(nghialam): Spawner class to solve this issue
  Text* info_ = nullptr;
  std::stringstream i_content_;
  
 public:
  Game();
  ~Game();

  static Game* ME;
  static bool quit_game;
  static Player* player;
  static std::vector<Fighter*>* enemy;
  static Controller* controller;

  void loop();
  void render(int &scroll_offset, int& frames, Timer &cap_timer);
  void update();

  SDL_Renderer* get_renderer();
};

#endif //ASTEROID_GAME_H_
