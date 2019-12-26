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

}

void Entity::post_update() {
  spr->set_pos((cx_+xr_)*kGrid, (cy_+yr_)*kGrid);
  // spr->set_scale(dir, 1);
}

bool Entity::is_destroyed() { return destroyed_; }


