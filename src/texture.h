#ifndef ASTEROID_TEXTURE_H
#define ASTEROID_TEXTURE_H

#include "header.h"

class Texture {
 private:
  SDL_Texture* texture_;
  int width_;
  int height_;

 public:
  Texture();
  explicit Texture(const std::string& file_path);
  ~Texture();

  void render(int x, int y,
              SDL_Rect* clip = nullptr,
              double angle = 0.0, 
              SDL_Point* center = nullptr, 
              SDL_RendererFlip flip = SDL_FLIP_NONE);

  int get_w();
  int get_h();
};

#endif  // !ASTEROID_TEXTURE_H
