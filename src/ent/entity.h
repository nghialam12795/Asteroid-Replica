#ifndef ASTEROID_ENTITY_H_
#define ASTEROID_ENTITY_H_

#include "../sprite.h"

class Entity {
 private:
  bool destroyed_;
 
 protected:
  int cx_;
  int cy_;
  float xr_;
  float yr_;

 public:
  Entity(int x, int y);
  ~Entity();

  Sprite* spr = nullptr;
  uint8_t dir;

  // Movement distances
  float dx;
  float dy;

  bool is_destroyed();
  void destroy();
  void set_pos_utils(int x, int y);

  virtual void pre_update(); // for Action
  virtual void update(); // for Calculating, Logic, etc..
  virtual void post_update(); // for update position
};

#endif //ASTEROID_ENTITY_H_
