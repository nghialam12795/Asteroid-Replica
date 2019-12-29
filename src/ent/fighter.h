#ifndef ASTEROID_ENT_FIGHTER_H
#define ASTEROID_ENT_FIGHTER_H

#include "entity.h"
#include "../timer.h"

class Fighter : public Entity {
 private:
  const float flight_spd_ = 0.02;
  Timer shoot_delay_;
  void check_shoot_state_();

 public:
  Fighter(int x, int y);
  ~Fighter();
  
  void pre_update() override;
  void update() override;
  void post_update() override;
};

#endif  // !ASTEROID_ENT_FIGHTER_H