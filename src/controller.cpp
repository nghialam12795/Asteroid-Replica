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
  // Escape
  if (state_[SDL_SCANCODE_ESCAPE]) {
    key_escape = true;
  } else {
    key_escape = false;
  }

  // Fire
  if (state_[SDL_SCANCODE_SPACE]) {
    key_fire = true;
  } else {
    key_fire = false;
  }

  // Up
  if (state_[SDL_SCANCODE_UP] || state_[SDL_SCANCODE_W]) {
    key_up = true;
  } else {
    key_up = false;
  }

  // Down
  if (state_[SDL_SCANCODE_DOWN] || state_[SDL_SCANCODE_S]) {
    key_down = true;
  } else {
    key_down = false;
  }

  // Left
  if (state_[SDL_SCANCODE_LEFT] || state_[SDL_SCANCODE_A]) {
    key_left = true;
  } else {
    key_left = false;
  }

  // Right
  if (state_[SDL_SCANCODE_RIGHT] || state_[SDL_SCANCODE_D]) {
    key_right = true;
  } else {
    key_right = false;
  }
}