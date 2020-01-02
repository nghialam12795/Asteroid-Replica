#include "obstacle.h"

#include "explosion.h"
#include "fighter.h"
#include "../constant.h"
#include "../assets.h"

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Obstacle::Obstacle(int x, int y) : Entity(x, y) {
  this->spr->set_sprite(*Assets::get_anim("obstacle_idle"));
  this->spr->set_scale(2, 2);
}

Obstacle::~Obstacle() { this->destroy(); }

// ************************ METHOD ***************************** //
void Obstacle::pre_update() {
  Entity::pre_update();

  x_pos = (cx_+xr_)*kGrid;
  if (x_pos >= (kScreenWidth + 20)) { this->destroy(); }
  y_pos = (cy_+yr_)*kGrid;

  dx -= fly_spd_;
}

void Obstacle::update() {
  Entity::update();
}

void Obstacle::post_update() {
  // Set position
  this->spr->set_pos(x_pos, y_pos);
  this->spr->play();
  if (this->anim_delay_ == 0) {
    this->spr->update();
    this->anim_delay_ = 8;
  }

  --this->anim_delay_;
}
