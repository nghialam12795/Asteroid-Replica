#ifndef ASTEROID_ENT_OBSTACLE_H_
#define ASTEROID_ENT_OBSTACLE_H_

#include "entity.h"

class Obstacle : public Entity{
 private:
  const float fly_spd_ = 0.02;

 public:
  Obstacle(int x, int y);
  ~Obstacle();

  void pre_update() override;
  void update() override;
  void post_update() override;
};

#endif //ASTEROID_ENT_OBSTACLE_H_
