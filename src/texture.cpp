#include "texture.h"
#include "game.h"
#include "constant.h"


// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Texture::Texture() {
  texture_ = nullptr;
  width_ = 0;
  height_ = 0;
}

Texture::Texture(const std::string& file_path) {
  SDL_Surface* texture_surface = IMG_Load(file_path.c_str());
  texture_ = SDL_CreateTextureFromSurface(Game::ME->get_renderer(), texture_surface);
  width_ = texture_surface->w * kAutoScale;
  height_ = texture_surface->h * kAutoScale;

  SDL_FreeSurface(texture_surface);
}

Texture::~Texture() {
  free();
}

// ************************ METHOD ***************************** //
void Texture::render(int x, int y, SDL_Rect* clip) {
  SDL_Rect render_space = {x, y, width_, height_};
  if (clip != nullptr) {
    render_space.w = clip->w;
    render_space.h = clip->h;
  }

  SDL_RenderCopy(Game::ME->get_renderer(), texture_, clip, &render_space);
}

void Texture::free() {
  if (texture_ != nullptr) {
    SDL_DestroyTexture(texture_);
    texture_ = nullptr;
    width_ = 0;
    height_ = 0;
  }
}

int Texture::get_w() { return width_; }
int Texture::get_h() { return height_; }

