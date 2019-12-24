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
  SDL_SetWindowIcon(window_, Assets::get_logo());
  SDL_FreeSurface(Assets::get_logo());

  // Init time counter
  timer_.start();
  fps_counter_ = new Text("Game Start", 1, {255, 255, 255, 255});
  fps_counter_->render(kScreenWidth/2, 0);
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
  int scroll_offset = 0;
  int frames = 0;
  while (!Game::quit_game && main_event_->type != SDL_QUIT) {
    render(scroll_offset, frames);
    update();
  }
}

void Game::render(int &scroll_offset, int &frames) {
  --scroll_offset;
  if (scroll_offset < -Assets::get_bg()->get_w()) { scroll_offset = 0; }

  SDL_RenderClear(renderer_);
  // Render background
  Assets::get_bg()->render(scroll_offset, 0);
  Assets::get_bg()->render(scroll_offset + Assets::get_bg()->get_w(), 0);
  // Render text
  float avg_fps = frames / (timer_.get_time() / 1000.f);
  if (avg_fps > 2000000) { avg_fps = 0; }

  time_text.str( "" );
  time_text << "FPS: " << avg_fps;
  fps_counter_->render((kScreenWidth - fps_counter_->get_w())/2, 0, time_text.str());

  SDL_RenderPresent(renderer_);
  ++frames;
}

void Game::update() {
  SDL_PollEvent(main_event_);
}

SDL_Renderer* Game::get_renderer() { return renderer_; }