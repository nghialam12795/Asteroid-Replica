#ifndef ASTEROID_UI_H
#define ASTEROID_UI_H

#include "../header.h"

class Text {
 private:
  SDL_Texture* content_;
  int font_size_;
  int font_w_;
  int font_h_;
  SDL_Color color_{};

 public:
  Text();
  explicit Text(const std::string& text,
                int font_size = 16,
                SDL_Color color = {0, 0, 0, 255}
                );
  ~Text();

  int get_w();
  int get_h();
  void set_content(const std::string& text);
  void render(int x, int y, const std::string& text = "");
};

#endif // !ASTEROID_UI_H