#include "sprite.h"

#include <iostream>

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Sprite::Sprite() {
  x_ = 0;
  y_ = 0;
  scale_x_ = 1;
  scale_y_ = 1;

  f_start = 0;
  f_cur = 0;
  f_end = 0;
}

Sprite::Sprite(const std::vector<std::string> &sprites_path) {
  x_ = 0;
  y_ = 0;
  scale_x_ = 1;
  scale_y_ = 1;
  f_start = 0;
  f_cur = 0;
  f_end = sprites_path.size() - 1;
  set_sprite(sprites_path);
}

Sprite::~Sprite() {
  for (auto i : sprites_) { delete(i); }
  x_ = 0;
  y_ = 0;
  scale_x_ = 1;
  scale_y_ = 1;
  f_start = 0;
  f_cur = 0;
  f_end = 0;
}

// ************************ METHOD ***************************** //
void Sprite::play() {
  SDL_Rect scale_ref = {0, 0, sprites_[f_cur]->get_w()*scale_x_, sprites_[f_cur]->get_h()*scale_y_};
  sprites_[f_cur]->render(x_, y_, &scale_ref);
}

void Sprite::set_sprite(const std::vector<std::string> &sprites_path) {
  if (!sprites_.empty()) {
    for (auto i : sprites_) { delete(i); }
  }

  f_start = 0;
  f_cur = 0;
  f_end = sprites_path.size() - 1;
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

int Sprite::get_scale_x() { return scale_x_; }
int Sprite::get_scale_y() { return scale_y_; }
int Sprite::get_w() { return sprites_[f_cur]->get_w(); }
int Sprite::get_h() { return sprites_[f_cur]->get_h(); }

void Sprite::update() {
  if (f_cur == f_end) { f_cur = 0; }
  else { ++f_cur; }
}

