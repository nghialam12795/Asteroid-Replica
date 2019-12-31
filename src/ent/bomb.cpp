#include "bomb.h"

#include "bullet.h"
#include "fighter.h"
#include "explosion.h"
#include "../assets.h"
#include "../constant.h"

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Bomb::Bomb(int x, int y, BOMB_DIR fly_dir) : Entity(x, y) {
  this->spr->set_sprite(*Assets::get_anim("bomb_coming"));
  this->spr->set_scale(2, 2);
  this->fly_dir_ = fly_dir;
}

Bomb::~Bomb() {
  this->destroy();
}

// ************************ METHOD ***************************** //
void Bomb::pre_update() {
  Entity::pre_update();
  if (has_collide_()) { this -> destroy(); }

  x_pos = (cx_+xr_)*kGrid;
  if (x_pos <= -20 || y_pos <= -20 || y_pos >= kScreenHeight+20) { this->destroy(); }
  y_pos = (cy_+yr_)*kGrid;

  if (fly_dir_ == BOMB_DIR::LEFT) { dx -= fire_spd_; }
  else if (fly_dir_ == BOMB_DIR::UP) { dx -= fire_spd_; dy -= 0.1;}
  else if (fly_dir_ == BOMB_DIR::DOWN) { dx -= fire_spd_; dy += 0.1;}
}

void Bomb::update() {
  Entity::update();
}

void Bomb::post_update() {
  Entity::post_update();
}

template<typename Base, typename T>
bool Bomb::is_instance_of(const T *ptr) {
  return dynamic_cast<const Base*>(ptr) != nullptr;
}

bool Bomb::has_collide_() {
  for (auto* e : *Entity::ALL) {
    if (e != this &&
        !is_instance_of<Explosion>(e) &&
        !is_instance_of<Fighter>(e) &&
        !is_instance_of<Bullet>(e) &&
        !is_instance_of<Bomb>(e))
      if (this->x_pos < e->x_pos + e->spr->get_w() &&
          this->x_pos + this->spr->get_w() > e->x_pos &&
          this->y_pos < e->y_pos + e->spr->get_h() &&
          this->y_pos + this->spr->get_h() > e->y_pos)
        return true;
  }
  return false;
}
