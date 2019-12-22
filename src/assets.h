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

  static SDL_Surface* logo_;
  static Texture* background_;

 public:
  Assets();
  ~Assets();
  SDL_Surface* get_logo();
  Texture* get_bg();
};

#endif  // ASTEROID_ASSETS_H_
