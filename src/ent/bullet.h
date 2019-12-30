#ifndef ASTEROID_ENT_BULLET_H_
#define ASTEROID_ENT_BULLET_H_

#include "entity.h"

class Bullet : public Entity {
 private:
  const float fire_spd_ = 0.3;

 protected:
  bool has_collide_() override;

 public:
  Bullet(int x, int y);
  ~Bullet();

  template<typename Base, typename T> // Currently duplicate with player
  bool is_instance_of(const T*); // TODO(nghialam): Create a framework to solve this

  void pre_update() override;
  void update() override;
  void post_update() override;
};

#endif //ASTEROID_ENT_BULLET_H_
