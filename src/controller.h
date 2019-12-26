#ifndef ASTEROID_CONTROLLER_H
#define ASTEROID_CONTROLLER_H

#include "header.h"

class Controller
{
 private:
  const static uint8_t* state_;

 public : Controller();
  ~Controller();

  bool key_left;
  bool key_right;
  bool key_up;
  bool key_down;
  bool key_fire;
  bool key_escape;

  void get_input();
};

#endif // !ASTEROID_CONTROLLER_H