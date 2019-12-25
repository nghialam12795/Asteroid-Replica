#include "player.h"

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Player::Player(int x, int y) : Entity(x, y) {}

Player::~Player() = default;

// ************************ METHOD ***************************** //
void Player::pre_update() {
  Entity::pre_update();
}

//void Player::update() {
//  Entity::update();
//}

void Player::post_update() {
  Entity::post_update();
}
