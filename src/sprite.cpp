#include "sprite.h"

#include <iostream>

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Sprite::Sprite() {
  x_ = 0;
  y_ = 0;
  scale_x_ = 1;
  scale_y_ = 1;
}

Sprite::Sprite(const std::vector<std::string> &sprites_path) {
  x_ = 0;
  y_ = 0;
  scale_x_ = 1;
  scale_y_ = 1;
  set_sprite(sprites_path);
}

Sprite::~Sprite() {
  for (auto i : sprites_) { delete(i); }
  x_ = 0;
  y_ = 0;
  scale_x_ = 1;
  scale_y_ = 1;
}

// ************************ METHOD ***************************** //
void Sprite::play() {
  for (auto i : sprites_) {
    SDL_Rect scale_ref = {0, 0, i->get_w()*scale_x_, i->get_h()*scale_y_};
    i->render(x_, y_, &scale_ref);
    // TODO(nghialam) : fix unknown bug of render all frame
  }
}

void Sprite::set_sprite(const std::vector<std::string> &sprites_path) {
  if (!sprites_.empty()) {
    for (auto i : sprites_) { delete(i); }
  }

  for (const auto &i : sprites_path) { sprites_.push_back(new Texture(i)); }
}

void Sprite::set_pos(int x, int y) {
  this->x_ = x;
  this->y_ = y;
}

void Sprite::set_scale(int x, int y) {
  this->scale_x_ = x;
  this->scale_y_ = y;
}
