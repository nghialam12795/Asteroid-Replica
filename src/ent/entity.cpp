#include "entity.h"

#include "../constant.h"

std::vector<Entity*>* Entity::ALL = new std::vector<Entity*>;
std::vector<Entity*>* Entity::GC = new std::vector<Entity*>;

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Entity::Entity(int x, int y) {
  dx = 0;
  dy = 0;
  destroyed_ = false;
  dir = 1;
  spr = new Sprite();
  set_pos_utils(x, y);
  Entity::ALL->push_back(this);
}

Entity::~Entity() { destroy(); }


// ************************ METHOD ***************************** //

void Entity::set_pos_utils(int x, int y) {
  x_pos = x;
  y_pos = y;
  xr_ = 0.5;
  yr_ = 1;
  cx_ = (x_pos - xr_)/kGrid;
  cy_ = (y_pos - yr_)/kGrid;
}

void Entity::destroy() {
  if (!destroyed_) {
    destroyed_ = true;
    Entity::GC->push_back(this);
  }
}

bool Entity::has_collide_() {
  for (auto* e : *Entity::ALL) {
    if (e != this)
      if (this->x_pos < e->x_pos + e->spr->get_w() &&
          this->x_pos + this->spr->get_w() > e->x_pos &&
          this->y_pos < e->y_pos + e->spr->get_h() &&
          this->y_pos + this->spr->get_h() > e->y_pos)
        return true;
  }
  return false;
}

void Entity::dispose() {
  auto it = std::find(ALL->begin(), ALL->end(), this);
  ALL->erase(it);
  cx_ = 0;
  cy_ = 0;
  xr_ = 0;
  yr_ = 0;
  dir = 1;
  delete(spr);
  spr = nullptr;
}

void Entity::pre_update() {}

void Entity::update() {
  // ------------------------------------------------
  // Movement statistic management
  // ------------------------------------------------

  // X
  xr_ += dx;
  if (xr_ != 0) {
      while (xr_ > 1) { --xr_; ++cx_; }
      while (xr_ < 0) { ++xr_; --cx_; }
  }
  dx *= kFrict;

  // Y
  yr_ += dy;
  if (yr_ != 0) {
      while (yr_ > 1) { --yr_; ++cy_; }
      while (yr_ < 0) { ++yr_; --cy_; }
  }
  dy *= kFrict;
}

void Entity::post_update() {}

bool Entity::is_destroyed() { return destroyed_; }
