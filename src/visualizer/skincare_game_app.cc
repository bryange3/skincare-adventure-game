//
// Created by Bryan Ge on 11/14/20.
//

#include <visualizer/skincare_game_app.h>
#include "core/constants.h"
#include "cinder/audio/Voice.h"
#include "cinder/audio/Source.h"
#include "cinder/Unicode.h"

namespace skincare {

namespace visualizer {

using std::string;

SkincareGameApp::SkincareGameApp() {
  ci::app::setWindowSize(kWindowWidth, kWindowHeight);
}

void SkincareGameApp::setup() {
  keyboard_input_ = "";
  LoadGameEndAudio(kGameLoseAudio, kGameWinAudio);
  LoadProductsAudio(kGoodProductAudio, kBadProductAudio);
  game_ = Game(kGameDataFile);
}

void SkincareGameApp::draw() {
  ci::Color background_color(220, 220, 220);
  ci::gl::clear(background_color);
  skincare_game_canvas_.Render(game_.get_game_state(),
                               kWindowWidth, keyboard_input_);
}

void SkincareGameApp::keyDown(ci::app::KeyEvent event) {
  if (event.getCode() == ci::app::KeyEvent::KEY_RETURN) {
    game_.UpdateGame(keyboard_input_);
    if (game_.get_game_state().get_product_selection_response()
        == kGoodProduct) {
      label_to_good_product_audio_.at(random(kGoodProductAudio))->start();
    } else if (game_.get_game_state().get_product_selection_response()
        == kBadProduct) {
      label_to_bad_product_audio_.at(random(kBadProductAudio))->start();
    }
    keyboard_input_.clear();
  } else if (event.getCode() == ci::app::KeyEvent::KEY_BACKSPACE) {
    // https://stackoverflow.com/questions/2310939/remove-last-character-from-c-string
    if (keyboard_input_.size() > 0) {
      keyboard_input_ = keyboard_input_.substr(0, keyboard_input_.size() - 1);
    }
  } else if (event.getCharUtf32()) {
    std::u32string strUtf32(1, event.getCharUtf32());
    keyboard_input_ += ci::toUtf8(strUtf32);
  }

  const std::string &game_step = game_.get_game_state().get_game_step();
  if (game_step == kGameStepFinal) {
    const GameState &game_state = game_.get_game_state();
    PlayGameEndAudio(game_state);
  }
}

void SkincareGameApp::LoadGameEndAudio(const std::string &game_lose_audio,
                                       const std::string &game_win_audio) {
  // https://libcinder.org/docs/guides/audio/index.html
  ci::audio::SourceFileRef
      game_lose_src = ci::audio::load(ci::app::loadAsset(game_lose_audio));
  ci::audio::VoiceRef game_lose = ci::audio::Voice::create(game_lose_src);
  label_to_game_end_audio_.insert({kAudioGameLose, game_lose});

  ci::audio::SourceFileRef
      game_win_src = ci::audio::load(ci::app::loadAsset(game_win_audio));
  ci::audio::VoiceRef game_win = ci::audio::Voice::create(game_win_src);
  label_to_game_end_audio_.insert({kAudioGameWin, game_win});
}

void SkincareGameApp::PlayGameEndAudio(const GameState &game_state) {
  const int kGameWinMinScore = 10;
  if (game_state.get_player().get_score() < kGameWinMinScore) {
    label_to_game_end_audio_.at(kAudioGameLose)->start();
  } else {
    label_to_game_end_audio_.at(kAudioGameWin)->start();
  }
}

void SkincareGameApp::LoadProductsAudio(const std::vector<string> &good_product_audio,
                                        const std::vector<string> &bad_product_audio) {
  label_to_good_product_audio_ = LoadAudioFromFilenames(good_product_audio);
  label_to_bad_product_audio_ = LoadAudioFromFilenames(bad_product_audio);
}

std::map<string, ci::audio::VoiceRef> SkincareGameApp::LoadAudioFromFilenames(
    const std::vector<string> &audio_filenames) {
  std::map<string, ci::audio::VoiceRef> file_to_audio;
  for (std::string filename : audio_filenames) {
    ci::audio::SourceFileRef
        src = ci::audio::load(ci::app::loadAsset(filename));
    ci::audio::VoiceRef voice = ci::audio::Voice::create(src);
    file_to_audio.insert({filename, voice});
  }
  return file_to_audio;
}

}  // namespace visualizer

}  // namespace skincare