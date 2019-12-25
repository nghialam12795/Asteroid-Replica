#include "assets.h"

// ********************* STATIC VARIABLES ********************** //
bool Assets::is_init_ = false;
const std::string Assets::res_path_ = "../res/"; // TODO(nghialam): Find a way to embed resource
const std::string Assets::logo_name_ = "logo.png";
const std::string Assets::bg_name_ = "background.png";
const std::string Assets::font_name_ = "m6x11.ttf";
SDL_Surface* Assets::logo_ = nullptr;
Texture* Assets::background_ = nullptr;
TTF_Font* Assets::font_ = nullptr;

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Assets::Assets() {
  if (!is_init_) {
    int img_flg = IMG_INIT_PNG;
    IMG_Init(img_flg);
    anim_db_ = nullptr;

    // Init logo
    std::string logo_path = res_path_ + logo_name_;
    logo_ = IMG_Load(logo_path.c_str());

    // Init background
    std::string bg_path = res_path_ + bg_name_;
    background_ = new Texture(bg_path);

    // Init font
    TTF_Init();
    std::string font_path = res_path_ + font_name_;
    font_ = TTF_OpenFont(font_path.c_str(), 16);

    // -------------------------------------------------------
    // ANIMATION
    // -------------------------------------------------------
    std::vector<std::string> anim_paths;
    anim_paths.reserve(24);
    for (int i = 0; i < 24; ++i) { anim_paths.push_back(res_path_ + "ent/player/player_idle_" + std::to_string(i + 1) + ".png"); }
    (*anim_db_)["player_idle"] = anim_paths;
  }

  is_init_ = true;
}

Assets::~Assets() {
  IMG_Quit();
  TTF_Quit();
  delete background_;
  background_ = nullptr;
}

// ************************ METHOD ***************************** //
SDL_Surface* Assets::get_logo() { return logo_; }
Texture* Assets::get_bg() { return background_; }
TTF_Font* Assets::get_font() { return font_; }

std::vector<std::string> Assets::get_anim(const std::string& anim_name) {
  return anim_db_->find(anim_name)->second;
}
