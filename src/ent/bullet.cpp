#include "bullet.h"
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
}

void Bullet::update() {
  Entity::update();

  int x_pos = (cx_+xr_)*kGrid;
  if (x_pos >= (kScreenWidth + 20)) { this->destroy(); }
  int y_pos = (cy_+yr_)*kGrid;

  dx += fire_spd_;
  // Set position
  spr->set_pos(x_pos, y_pos);
  this->spr->play();
  this->spr->update();
}

void Bullet::post_update() {
  Entity::post_update();
}
