//
// Created by Bryan Ge on 11/14/20.
//

#pragma once

#include <core/game.h>
#include <cinder/audio/Voice.h>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "skincare_game_canvas.h"

namespace skincare {

namespace visualizer {

/**
 * Skincare game Cinder application.
 */
class SkincareGameApp : public ci::app::App {
 public:
  SkincareGameApp();

  // https://www.techiedelight.com/get-random-value-stl-containers-cpp/
  template<typename T>
  T random(std::vector<T> const &v) {
    int r = rand() % v.size();
    return v.at(r);
  }

  /**
   * Sets up the skincare game by loading audio and game data files.
   */
  void setup() override;

  /**
   * Draws skincare game components.
   */
  void draw() override;

  /**
   * Handles keyboard input.
   *
   * @param event key input event
   */
  void keyDown(ci::app::KeyEvent event) override;

 private:
  const std::string kGameDataFile = "../src/resources/skincare_products.json";
  const std::string kGameLoseAudio = "gamelose.mp3";
  const std::string kGameWinAudio = "gamewin.mp3";

  const std::vector<std::string> kGoodProductAudio =
      {"ilike.mp3", "nicechoice.mp3", "oksisiseeu.mp3", "popoffgreatchoice.mp3",
       "thatsnice.mp3"};
  const std::vector<std::string> kBadProductAudio =
      {"notgreat.mp3", "oooidontlike.mp3", "theresbetter.mp3", "uhoh.mp3"};

  const size_t kWindowHeight = 900;
  const size_t kWindowWidth = 1440;

  std::map<std::string, ci::audio::VoiceRef> label_to_good_product_audio_;
  std::map<std::string, ci::audio::VoiceRef> label_to_bad_product_audio_;
  std::map<std::string, ci::audio::VoiceRef> label_to_game_end_audio_;

  SkincareGameCanvas skincare_game_canvas_;
  Game game_;
  std::string keyboard_input_;

  /**
   * Load products response audio.
   *
   * @param good_product_audio all good product audio filenames
   * @param bad_product_audio all bad product audio filenames
   */
  void LoadProductsAudio(const std::vector<std::string> &good_product_audio,
                         const std::vector<std::string> &bad_product_audio);

  /**
   * Load audio from multiple filenames.
   *
   * @param audio_filenames all audio filenames to be loaded
   * @return map of filenames to their respective VoiceRef objects
   */
  std::map<std::string,
           ci::audio::VoiceRef> LoadAudioFromFilenames(const std::vector<std::string> &audio_filenames);

  /**
   * Loads game ending audio.
   *
   * @param game_lose_audio name of game lose audio file
   * @param game_win_audio name of game win audio file
   */
  void LoadGameEndAudio(const std::string &game_lose_audio,
                        const std::string &game_win_audio);

  /**
   * Play the proper game ending audio according to whether the player has
   * won (earned more than or equal to 10 points) or lost (earned less than 10
   * points).
   *
   * @param game_state game state
   */
  void PlayGameEndAudio(const GameState &game_state);
};

}  // namespace visualizer

}  // namespace skincare
