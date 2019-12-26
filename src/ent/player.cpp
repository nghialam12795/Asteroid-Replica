#include "player.h"

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Player::Player(int x, int y) : Entity(x, y) {
  this->spr->set_scale(4, 4);
}

Player::~Player() = default;

// ************************ METHOD ***************************** //
void Player::pre_update() {
  Entity::pre_update();
}

void Player::update() {
 Entity::update();
 this->spr->update();
 this->xr_ += 0.1;
}

void Player::post_update() {
  Entity::post_update();
}
