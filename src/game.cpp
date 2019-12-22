#include "game.h"

#include "constant.h"

// ********************* STATIC VARIABLES ********************** //
Game* Game::ME = nullptr;
bool Game::quit_game = false;

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
  SDL_SetWindowIcon(window_, game_assets_->get_logo());
  SDL_FreeSurface(game_assets_->get_logo());
}

Game::~Game() {
  delete main_event_;
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);

  renderer_ = nullptr;
  window_ = nullptr;

  SDL_Quit();
}

// ************************ METHOD ***************************** //
void Game::loop() {
  int scroll_offset = 0;
  while (!Game::quit_game && main_event_->type != SDL_QUIT) {
    render(scroll_offset);
    update();
  }
}

void Game::render(int &scroll_offset) {
  --scroll_offset;
  if (scroll_offset < -game_assets_->get_bg()->get_w()) { scroll_offset = 0; }

  // SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(renderer_);
  // Render background
  game_assets_->get_bg()->render(scroll_offset, 0);
  game_assets_->get_bg()->render(scroll_offset + game_assets_->get_bg()->get_w(), 0);
  SDL_RenderPresent(renderer_);
}

void Game::update() {
  SDL_PollEvent(main_event_);
}

SDL_Renderer* Game::get_renderer() { return renderer_; }