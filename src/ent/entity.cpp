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


