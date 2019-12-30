#ifndef ASTEROID_ENT_PLAYER_H_
#define ASTEROID_ENT_PLAYER_H_

#include "entity.h"
#include "../timer.h"

class Player : public Entity {
 private:
  const float flight_spd_ = 0.1;

  Timer shoot_delay_;
  void check_shoot_state_();

 protected:
  bool has_collide_() override;

 public:
  Player(int x, int y);
  virtual ~Player();

  template<typename Base, typename T>
  bool is_instance_of(const T*);

  bool is_shooting;
  void pre_update() override;
  void update() override;
  void post_update() override;
};

#endif //ASTEROID_ENT_PLAYER_H_
