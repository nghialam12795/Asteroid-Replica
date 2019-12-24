#include "timer.h"

#include <SDL.h>

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Timer::Timer() {
  begin_ = 0;
  end_ = 0;
  is_pause = false;
}
Timer::~Timer() = default;

// ************************ METHOD ***************************** //
void Timer::start() {
  is_pause = false;
  begin_ = SDL_GetTicks();
  end_ = 0;
}

void Timer::stop() {
  begin_ = 0;
  end_ = 0;
  is_pause = false;
}

void Timer::pause() {
  if (begin_ != 0 && !is_pause) {
    is_pause = true;
    end_ = SDL_GetTicks() - begin_;
    begin_ = 0;
  }
}

void Timer::unpause() {
  if (is_pause) {
    is_pause = false;
    begin_ = SDL_GetTicks() - end_;
    end_ = 0;
  }
}

unsigned int Timer::get_time() {
  unsigned int time = 0;

  if (is_pause) {
    time = end_;
  } else if (begin_ != 0) {
    time = SDL_GetTicks() - begin_;
  }

  return time;
}





