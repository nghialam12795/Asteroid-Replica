#include "text.h"

#include <utility>
#include "../assets.h"
#include "../game.h"

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Text::Text() {
  content_ = nullptr;
  font_h_ = 0;
  font_w_ = 0;
  font_size_ = 0;
  color_ = {0, 0, 0, 255};
}

Text::~Text() {
  if (content_ != nullptr) {
    SDL_DestroyTexture(content_);
    content_ = nullptr;
    font_w_ = 0;
    font_h_ = 0;
    font_size_ = 0;
  }
}

Text::Text(const std::string& text, int font_size, SDL_Color color) {
  content_ = nullptr;
  font_size_ = font_size;
  color_ = color;
  set_content(text);
}

// ************************ METHOD ***************************** //
void Text::render(int x, int y, const std::string& text) {
  if (!text.empty()) {
    set_content(text);
  }

  SDL_Rect render_space = {x, y, font_w_*font_size_, font_h_*font_size_};
  SDL_RenderCopyEx( Game::ME->get_renderer(), 
                    content_, nullptr, 
                    &render_space, 
                    0.0, 
                    nullptr, 
                    SDL_FLIP_NONE);
}

void Text::set_content(const std::string& text) {
  if (content_ != nullptr) {
    SDL_DestroyTexture(content_);
    content_ = nullptr;
  }

  SDL_Surface* text_surface = TTF_RenderText_Solid(Assets::get_font(), text.c_str(), color_);
  content_ = SDL_CreateTextureFromSurface(Game::ME->get_renderer(), text_surface);
  font_h_ = text_surface->h;
  font_w_ = text_surface->w;
  SDL_FreeSurface(text_surface);
}

int Text::get_h() { return font_h_; }

int Text::get_w() { return font_w_; }