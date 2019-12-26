#ifndef ASTEROID_SPRITE_H_
#define ASTEROID_SPRITE_H_

#include <vector>
#include "texture.h"

class Sprite {
 private:
  std::vector<Texture*> sprites_;
  int x_;
  int y_;
  int scale_x_;
  int scale_y_;

  int f_start;
  int f_cur;
  int f_end;

 public:
  Sprite();
  explicit Sprite(const std::vector<std::string> &sprites_path);
  ~Sprite();

  void play();
  void set_sprite(const std::vector<std::string> &sprites_path);
  void set_pos(int x, int y);
  void set_scale(int x, int y);

  void update();
};

#endif //ASTEROID_SPRITE_H_
