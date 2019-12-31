#include "fighter.h"

#include "../assets.h"
#include "../constant.h"

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Fighter::Fighter(int x, int y) : Entity(x, y) {
  this->spr->set_sprite(*Assets::get_anim("fighter_idle"));
  this->spr->set_scale(1, 1);
}

Fighter::~Fighter() {
  this->destroy();
}

// ************************ METHOD ***************************** //
void Fighter::pre_update() {
  Entity::pre_update();
  if (has_collide_()) { this->destroy(); }

  x_pos = (cx_+xr_)*kGrid;
  if (x_pos <= -this->spr->get_w()) { this->destroy(); }
  y_pos = (cy_+yr_)*kGrid;

  dx -= flight_spd_;
}

void Fighter::update() {
  Entity::update();
}

void Fighter::post_update() {
  Entity::post_update();

  // Set position
  spr->set_pos(x_pos, y_pos);
  this->spr->play();
  this->spr->update();
}

void Fighter::check_shoot_state_() {

}