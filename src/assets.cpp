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
map< string, string >* Assets::audio_db_ = new map< string, string >;

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
    background_->set_h(background_->get_h()*4);
    background_->set_w(background_->get_w()*4);

    // Init font
    TTF_Init();
    string font_path = res_path_ + font_name_;
    font_ = TTF_OpenFont(font_path.c_str(), 16);

    // -------------------------------------------------------
    // ANIMATION
    // -------------------------------------------------------
    auto* ap_player_ = new vector<string>;
    auto* ap_bullet_ = new vector<string>;
    auto* ap_fighter_ = new vector<string>;
    auto* ap_explo_ = new vector<string>;
    auto* ap_obstacle_ = new vector<string>;
    auto* ap_bomb_ = new vector<string>;
    for (int i = 0; i < 24; ++i) {
      ap_player_->push_back(res_path_ + "ent/player/player_idle_" + to_string(i + 1) + ".png");
      ap_bullet_->push_back(res_path_ + "ent/bullet/bfire_" + to_string(i + 1) + ".png");
      ap_fighter_->push_back(res_path_ + "ent/fighter/fighter_" + to_string(i + 1) + ".png");
      ap_explo_->push_back(res_path_ + "ent/explosion/explosion_" + to_string(i + 1) + ".png");
      ap_obstacle_->push_back(res_path_ + "ent/obstacle/obstacles_" + to_string(i + 1) + ".png");
    }
    ap_bomb_->push_back(res_path_ + "ent/bullet/bomb_1.png");
    ap_bomb_->push_back(res_path_ + "ent/bullet/bomb_2.png");
    // Add to database
    anim_db_->insert({"player_idle", ap_player_});
    anim_db_->insert({"bullet_fire", ap_bullet_});
    anim_db_->insert({"fighter_idle", ap_fighter_});
    anim_db_->insert({"explosion", ap_explo_});
    anim_db_->insert({"obstacle_idle", ap_obstacle_});
    anim_db_->insert({"bomb_coming", ap_bomb_});

    // -------------------------------------------------------
    // AUDIO
    // -------------------------------------------------------
    audio_db_->insert({"overworld", res_path_ + "audio/overworld.wav"});
    audio_db_->insert({"fireball", res_path_ + "audio/fireball.wav"});
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

std::string Assets::get_audio(const std::string &audio_name) {
  return audio_db_->find(audio_name)->second;
}
