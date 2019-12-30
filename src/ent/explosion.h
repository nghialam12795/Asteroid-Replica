#ifndef ASTEROID_ENT_EXPLOSION_H_
#define ASTEROID_ENT_EXPLOSION_H_

#include "entity.h"

class Explosion : public Entity {
 private:
  const float float_spd_ = 0.3;
  int life_time_ = 0;

 public:
  Explosion(int x, int y);
  ~Explosion();

  void pre_update() override;
  void update() override;
  void post_update() override;
};

#endif //ASTEROID_ENT_EXPLOSION_H_
