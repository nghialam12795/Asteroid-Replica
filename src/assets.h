#ifndef ASTEROID_ASSETS_H_
#define ASTEROID_ASSETS_H_

#include <map>
#include <vector>
#include "header.h"
#include "texture.h"

class Assets {
 private:
  static bool is_init_;
  static const std::string res_path_;
  static const std::string logo_name_;
  static const std::string bg_name_;
  static const std::string font_name_;

  static std::map< std::string, std::vector<std::string>* >* anim_db_;
  static std::map< std::string, std::string>* audio_db_;

  static SDL_Surface* logo_;
  static Texture* background_;
  static TTF_Font* font_;

 public:
  Assets();
  ~Assets();
  static SDL_Surface* get_logo();
  static Texture* get_bg();
  static TTF_Font* get_font();
  static std::vector<std::string>* get_anim(const std::string& anim_name);
  static std::string get_audio(const std::string& audio_name);
};

#endif  // ASTEROID_ASSETS_H_
