#include "assets.h"
using namespace std;

// ********************* STATIC VARIABLES ********************** //
bool Assets::is_init_ = false;
const string Assets::res_path_ = "../res/"; // TODO(nghialam): Find a way to embed resource
const string Assets::logo_name_ = "logo.png";
const string Assets::bg_name_ = "background.png";
const string Assets::font_name_ = "m6x11.ttf";
SDL_Surface* Assets::logo_ = nullptr;
Texture* Assets::background_ = nullptr;
TTF_Font* Assets::font_ = nullptr;

map< string, vector<string>* >* Assets::anim_db_ = new map< string, vector<string>* >;

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Assets::Assets() {
  if (!is_init_) {
    int img_flg = IMG_INIT_PNG;
    IMG_Init(img_flg);

    // Init logo
    string logo_path = res_path_ + logo_name_;
    logo_ = IMG_Load(logo_path.c_str());

    // Init background
    string bg_path = res_path_ + bg_name_;
    background_ = new Texture(bg_path);
    background_->set_h(background_->get_h()*8);
    background_->set_w(background_->get_w()*8);

    // Init font
    TTF_Init();
    string font_path = res_path_ + font_name_;
    font_ = TTF_OpenFont(font_path.c_str(), 16);

    // -------------------------------------------------------
    // ANIMATION
    // -------------------------------------------------------
    vector<string>* anim_paths = new vector<string>;
    for (int i = 0; i < 24; ++i) {
      anim_paths->push_back(res_path_ + "ent/player/player_idle_" + to_string(i + 1) + ".png");
    }
    anim_db_->insert({"player_idle", anim_paths});
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

vector<string>* Assets::get_anim(const string& anim_name) {
  return anim_db_->find(anim_name)->second;
}
