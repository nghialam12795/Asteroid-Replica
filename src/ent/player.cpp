#include "player.h"

#include "../game.h"

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Player::Player(int x, int y) : Entity(x, y) {
  this->spr->set_scale(2, 2);
}

Player::~Player() = default;

// ************************ METHOD ***************************** //
void Player::pre_update() {
  Entity::pre_update();
}

void Player::update() {
  Entity::update();
  this->spr->play();
  this->spr->update();

  if (Game::ME->controller->key_up) {
    dy -= flight_spd_;
  } else if (Game::ME->controller->key_down) {
    dy += flight_spd_;
  } else if (Game::ME->controller->key_left) {
    dx -= flight_spd_;
  } else if (Game::ME->controller->key_right) {
    dx += flight_spd_;
  }

}

void Player::post_update() {
  Entity::post_update();
}
