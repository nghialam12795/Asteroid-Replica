#include "controller.h"

const uint8_t* Controller::state_ = SDL_GetKeyboardState(NULL);

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Controller::Controller() {
  key_left = false;
  key_right = false;
  key_up = false;
  key_down = false;
  key_fire = false;
  key_escape = false;
}

Controller::~Controller() {
  key_left = false;
  key_right = false;
  key_up = false;
  key_down = false;
  key_fire = false;
  key_escape = false;
  delete (state_);
  state_ = nullptr;
}

// ************************ METHOD ***************************** //

void Controller::get_input() {
  key_escape = state_[SDL_SCANCODE_ESCAPE] != 0;
  key_fire = state_[SDL_SCANCODE_SPACE] != 0;
  key_up = state_[SDL_SCANCODE_UP] || state_[SDL_SCANCODE_W];
  key_down = state_[SDL_SCANCODE_DOWN] || state_[SDL_SCANCODE_S];
  key_left = state_[SDL_SCANCODE_LEFT] || state_[SDL_SCANCODE_A];
  key_right = state_[SDL_SCANCODE_RIGHT] || state_[SDL_SCANCODE_D];
}