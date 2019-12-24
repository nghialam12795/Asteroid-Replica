#ifndef ASTEROID_TIMER_H_
#define ASTEROID_TIMER_H_

class Timer {
 private:
  unsigned int begin_;
  unsigned int end_;
  bool is_pause;

 public:
  Timer();
  ~Timer();

  void start();
  void stop();
  void pause();
  void unpause();

  unsigned int get_time();
};

#endif //ASTEROID_TIMER_H_
