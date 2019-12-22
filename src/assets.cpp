#include "assets.h"

// ********************* STATIC VARIABLES ********************** //
bool Assets::is_init_ = false;
const std::string Assets::res_path_ = "./res/";
const std::string Assets::logo_name_ = "logo.png";
const std::string Assets::bg_name_ = "background.png";
SDL_Surface* Assets::logo_ = nullptr;
Texture* Assets::background_ = nullptr;

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Assets::Assets() {
  if (!is_init_) {
    int img_flg = IMG_INIT_PNG;
    IMG_Init(img_flg);

    // Init logo
    std::string logo_path = res_path_ + logo_name_;
    logo_ = IMG_Load(logo_path.c_str());

    // Init background
    std::string file_path = res_path_ + bg_name_;
    background_ = new Texture(file_path.c_str());
  }

  is_init_ = true;
}

Assets::~Assets() {
  IMG_Quit();

  delete background_;
  background_ = nullptr;
}

// ************************ METHOD ***************************** //
SDL_Surface* Assets::get_logo() { return logo_; }
Texture* Assets::get_bg() { return background_; }