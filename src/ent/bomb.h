#ifndef ASTEROID_ENT_BOMB_H_
#define ASTEROID_ENT_BOMB_H_

#include "entity.h"

enum class BOMB_DIR {
  UP,
  DOWN,
  LEFT
};

class Bomb : public Entity {
 private:
  const float fire_spd_ = 0.3;
  BOMB_DIR fly_dir_;

 protected:
  bool has_collide_() override;

 public:
  Bomb(int x, int y, BOMB_DIR fly_dir);
  ~Bomb();

  template<typename Base, typename T> // Currently duplicate with player
  bool is_instance_of(const T*); // TODO(nghialam): Create a framework to solve this

  void pre_update() override;
  void update() override;
  void post_update() override;
};

#endif //ASTEROID_ENT_BOMB_H_
