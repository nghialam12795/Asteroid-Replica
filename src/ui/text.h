#ifndef ASTEROID_UI_H
#define ASTEROID_UI_H

#include <string>
#include <SDL_ttf.h>

class Text {
 private:
  TTF_Font* font_;
  int font_w_;
  int font_h_;
  SDL_Color color_;

 public:
  Text(const std::string& font_path);
  ~Text();

  void render(std::string text, 
              int x, int y, 
              int font_size = 16,
              SDL_Color color = {0, 0, 0, 255});
};

#endif // !ASTEROID_UI_H