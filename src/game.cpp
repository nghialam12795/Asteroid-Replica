#include "game.h"

#include <random>

#include "constant.h"
#include "ent/bullet.h"
#include "ent/fighter.h"

// ********************* STATIC VARIABLES ********************** //
Game* Game::ME = nullptr;
bool Game::quit_game = false;
Player* Game::player = new Player(0, 0);
Controller* Game::controller = new Controller;

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Game::Game() {
  ME = this;
  Game::quit_game = false;

  SDL_Init(SDL_INIT_VIDEO);
  window_ = SDL_CreateWindow("Asteroid Replica",
                             SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED,
                             kScreenWidth,
                             kScreenHeight,
                             SDL_WINDOW_SHOWN);

  if (window_ == nullptr) {
    Game::quit_game = true;
  }

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
  main_event_ = new SDL_Event();

  // Init Assets
  game_assets_ = new Assets();

  // Set window icon
  SDL_SetWindowIcon(window_, Assets::get_logo());
  SDL_FreeSurface(Assets::get_logo());

  // Init time counter
  timer_.start();
  fps_counter_ = new Text("Game Start", 1, {255, 255, 255, 255});
  fps_counter_->render(kScreenWidth/2, 0);

  // Init Entities
  player->spr->set_sprite(*Assets::get_anim("player_idle"));
}

Game::~Game() {
  delete main_event_;
  delete game_assets_;
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);

  renderer_ = nullptr;
  window_ = nullptr;

  SDL_Quit();
}

// ************************ METHOD ***************************** //
void Game::loop() {
  Timer cap_timer; // For capping FPS
  int scroll_offset = 0;
  int frames = 0;
  while (!Game::quit_game && main_event_->type != SDL_QUIT) {
    cap_timer.start();
    SDL_RenderClear(renderer_);
    render(scroll_offset, frames, cap_timer);
    update();
    SDL_RenderPresent(renderer_);
  }
}

void Game::render(int &scroll_offset, int &frames, Timer &cap_timer) {
  --scroll_offset;
  if (scroll_offset < -Assets::get_bg()->get_w()) { scroll_offset = 0; }

  // Render background
  Assets::get_bg()->render(scroll_offset, 0);
  Assets::get_bg()->render(scroll_offset + Assets::get_bg()->get_w(), 0);
  // Render text
  float avg_fps = frames / (timer_.get_time() / 1000.f);
  if (avg_fps > 2000000) { avg_fps = 0; }

  time_text.str( "" );
  time_text << "FPS: " << avg_fps;
  fps_counter_->render(kScreenWidth - fps_counter_->get_w(), 0, time_text.str());

  ++frames;

  // Delay for render at wanted FPS
  int screen_per_frame = 1000 / kGameFPS; // ms/maximum frame rate
  if (cap_timer.get_time() < screen_per_frame) { SDL_Delay(screen_per_frame - cap_timer.get_time()); }
}

void Game::update() {
  SDL_PollEvent(main_event_);
  controller->get_input();

  // Entities update
  for (auto* e : *Entity::ALL) if (!e->is_destroyed()) e->pre_update();
  for (auto* e : *Entity::ALL) if (!e->is_destroyed()) e->update();
  for (auto* e : *Entity::ALL) if (!e->is_destroyed()) e->post_update();
  if (player->is_shooting) {
    Bullet* bullet_ = new Bullet(player->x_pos + player->spr->get_w()/2, player->y_pos - 8);
    player->is_shooting = false;
  }

  ++enemy_spawn_;
  if (enemy_spawn_ == 200) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, kScreenHeight);
    Fighter* fighter_ = new Fighter(kScreenWidth, dis(gen));
    enemy_spawn_ = 0;
  }

  // Clean garbage
  if (!Entity::GC->empty()) {
    for (auto* e : *Entity::GC) { e->dispose(); }
    Entity::GC->clear();
  }
}

SDL_Renderer* Game::get_renderer() { return renderer_; }