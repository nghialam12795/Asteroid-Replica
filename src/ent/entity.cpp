#include "entity.h"

#include "../constant.h"


// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Entity::Entity(int x, int y) {
  destroyed_ = false;
  dir = 1;
  spr = new Sprite();
  set_pos_utils(x, y);
}

Entity::~Entity() {
  cx_ = 0;
  cy_ = 0;
  xr_ = 0;
  yr_ = 0;
  dir = 1;
  delete(spr);
  spr = nullptr;
}


// ************************ METHOD ***************************** //

void Entity::set_pos_utils(int x, int y) {
  cx_ = x;
  cy_ = y;
  xr_ = 0.5;
  yr_ = 1;
}

void Entity::destroy() {
  if (!destroyed_) {
  }
}

void Entity::pre_update() {
}

void Entity::update() {
  // ------------------------------------------------
  // Movement statistic management
  // ------------------------------------------------

  // X
  xr_ += dx;
  while (xr_ > 1) { --xr_; ++cx_; }
  while (xr_ < 0) { ++xr_; --cx_; }
  dx *= kFrict;

  // Y
  yr_ += dy;
  while (yr_ > 1) { --yr_; ++cy_; }
  while (yr_ < 0) { ++yr_; --cy_; }
  dy *= kFrict;
}

void Entity::post_update() {
  spr->set_pos((cx_+xr_)*kGrid, (cy_+yr_)*kGrid);
  spr->set_scale(dir * spr->get_scale_x(), 1); // Direction
}

bool Entity::is_destroyed() { return destroyed_; }


