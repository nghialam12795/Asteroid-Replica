#include "explosion.h"

#include "../assets.h"

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Explosion::Explosion(int x, int y) : Entity(x, y) {
  this->spr->set_sprite(*Assets::get_anim("explosion"));
  this->spr->set_scale(2, 2);
}

Explosion::~Explosion() = default;

// ************************ METHOD ***************************** //
void Explosion::pre_update() {
  Entity::pre_update();
  dx -= float_spd_;
  if (life_time_ == 24) {
    life_time_ = 0 ;
    this->destroy();
  } // Just need to render 24frames
}

void Explosion::update() { Entity::update(); }

void Explosion::post_update() {
  Entity::post_update();
  ++life_time_;
}


