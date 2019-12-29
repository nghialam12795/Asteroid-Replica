#include "bullet.h"

#include "../game.h"
#include "../assets.h"
#include "../constant.h"

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Bullet::Bullet(int x, int y) : Entity(x, y) {
  this->spr->set_sprite(*Assets::get_anim("bullet_fire"));
  this->spr->set_scale(2, 2);
}
Bullet::~Bullet() {
  this->destroy();
}

// ************************ METHOD ***************************** //

void Bullet::pre_update() {
  Entity::pre_update();
  if (has_collide_()) { this -> destroy(); }

  x_pos = (cx_+xr_)*kGrid;
  if (x_pos >= (kScreenWidth + 20)) { this->destroy(); }
  y_pos = (cy_+yr_)*kGrid;

  dx += fire_spd_;
}

void Bullet::update() {
  Entity::update();
  
  // Set position
  spr->set_pos(x_pos, y_pos);
  this->spr->play();
  this->spr->update();
}

void Bullet::post_update() {
  Entity::post_update();
}

bool Bullet::has_collide_() {
  for (auto* e : *Entity::ALL) {
    if (e != this && e!=Game::player)
      if (this->x_pos < e->x_pos + e->spr->get_w() &&
          this->x_pos + this->spr->get_w() > e->x_pos &&
          this->y_pos < e->y_pos + e->spr->get_h() &&
          this->y_pos + this->spr->get_h() > e->y_pos)
        return true;
  }
  return false;
}
