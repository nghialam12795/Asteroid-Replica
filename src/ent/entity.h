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

  static std::vector<Entity*>* ALL;
  static std::vector<Entity*>* GC; // Garbage Collection

  Sprite* spr = nullptr;
  uint8_t dir;

  // Movement distances
  float dx;
  float dy;
  int x_pos;
  int y_pos;

  bool is_destroyed();
  void destroy();
  void dispose();
  void set_pos_utils(int x, int y);

  virtual bool has_collide_();

  virtual void pre_update(); // for Action
  virtual void update(); // for Calculating, Logic, etc..
  virtual void post_update(); // for update position
};

#endif //ASTEROID_ENTITY_H_
