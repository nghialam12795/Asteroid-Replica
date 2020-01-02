#include "audio.h"

#include "assets.h"

// *************** CONSTRUCTOR & DESTRUCTOR ******************** //
Audio::Audio() {
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

  game_music_.push_back(load_music("overworld"));

  game_chunk_.push_back(load_chunk("fireball"));

  Audio::cur_music_ = MUSIC::NOTHING;
  set_volume(100);
}

Audio::~Audio() {
  for (auto* m : Audio::game_music_) Mix_FreeMusic(m);
  for (auto* c : Audio::game_chunk_) Mix_FreeChunk(c);
  game_music_.clear();
  game_chunk_.clear();
  Mix_Quit();
}


// ************************ METHOD ***************************** //
void Audio::play_mucic(MUSIC music_id) {
  Mix_PlayMusic(game_music_[static_cast<int>(music_id)], -1);
  Audio::cur_music_ = music_id;
}

void Audio::play_chunk(CHUNK chunk_id) {
  Mix_VolumeChunk(game_chunk_[static_cast<int>(chunk_id)], Audio::volume_);
  Mix_PlayChannel(-1, game_chunk_[static_cast<int>(chunk_id)], 0);
}

void Audio::set_volume(int volume) {
  Audio::volume_ = volume;
  Mix_VolumeMusic(Audio::volume_);
}

Mix_Music* Audio::load_music(const std::string& file_name) {
  return Mix_LoadMUS(Assets::get_audio(file_name).c_str());
}

Mix_Chunk* Audio::load_chunk(const std::string& file_name) {
  return Mix_LoadWAV(Assets::get_audio(file_name).c_str());
}
