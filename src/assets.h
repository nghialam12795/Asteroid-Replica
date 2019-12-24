#ifndef ASTEROID_ASSETS_H_
#define ASTEROID_ASSETS_H_

#include "header.h"
#include "texture.h"

class Assets {
 private:
  static bool is_init_;
  const static std::string res_path_;
  const static std::string logo_name_;
  const static std::string bg_name_;
  const static std::string font_name_;

  static SDL_Surface* logo_;
  static Texture* background_;
  static TTF_Font* font_;

 public:
  Assets();
  ~Assets();
  static SDL_Surface* get_logo();
  static Texture* get_bg();
  static TTF_Font* get_font();
};

#endif  // ASTEROID_ASSETS_H_
