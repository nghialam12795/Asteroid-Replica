#include "fighter.h"

#include "bomb.h"
#include "explosion.h"
#include "../assets.h"
#include "../constant.h"

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Fighter::Fighter(int x, int y) : Entity(x, y) {
  this->spr->set_sprite(*Assets::get_anim("fighter_idle"));
  this->spr->set_scale(1, 1);
  this->is_shooting = false;
  this->can_explode = true;
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

  check_shoot_state_();
  if (shoot_delay_.get_time() == 0) {
    is_shooting = true;
    shoot_delay_.start();
  }
}

void Fighter::update() { Entity::update(); }

void Fighter::post_update() { Entity::post_update(); }

void Fighter::check_shoot_state_() {
  if ((shoot_delay_.get_time()/1000.f) >= 4) { shoot_delay_.stop(); }
}

template<typename Base, typename T>
bool Fighter::is_instance_of(const T *ptr) {
  return dynamic_cast<const Base*>(ptr) != nullptr;
}

bool Fighter::has_collide_() {
  for (auto* e : *Entity::ALL) {
    if (e != this && !is_instance_of<Bomb>(e) && !is_instance_of<Explosion>(e))
      if (this->x_pos < e->x_pos + e->spr->get_w() &&
          this->x_pos + this->spr->get_w() > e->x_pos &&
          this->y_pos < e->y_pos + e->spr->get_h() &&
          this->y_pos + this->spr->get_h() > e->y_pos)
        return true;
  }
  return false;
}
