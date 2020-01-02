#ifndef ASTEROID_AUDIO_H_
#define ASTEROID_AUDIO_H_

#include <SDL_mixer.h>
#include <vector>
#include <string>

enum class MUSIC {
  MAIN_MENU,
  IN_GAME,
  NOTHING,
};

enum class CHUNK {
  BULLET_FIRE,
  BOMB,
  EXPLOSION,
};

class Audio {
 private:
  static std::vector<Mix_Music*> game_music_;
  static std::vector<Mix_Chunk*> game_chunk_;
  static MUSIC cur_music_;
  static int volume_;

 public:
  Audio();
  ~Audio();

  void play_mucic(MUSIC music_id);
  void play_chunk(CHUNK chunk_id);
  static void set_volume(int volume);

  static Mix_Music* load_music(const std::string& file_name);
  static Mix_Chunk* load_chunk(const std::string& file_name);
};

#endif //ASTEROID_AUDIO_H_
