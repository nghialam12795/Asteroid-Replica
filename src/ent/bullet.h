#ifndef ASTEROID_ENT_BULLET_H_
#define ASTEROID_ENT_BULLET_H_

#include "entity.h"

class Bullet : public Entity {
 private:
  const float fire_spd_ = 0.3;

 public:
  Bullet(int x, int y);
  ~Bullet();

  void pre_update() override;
  void update() override;
  void post_update() override;
};

#endif //ASTEROID_ENT_BULLET_H_
