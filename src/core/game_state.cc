//
// Created by Bryan Ge on 11/28/20.
//

#include "core/game_state.h"
#include "core/constants.h"

namespace skincare {

GameState::GameState() {
  game_step_ = kGameStepGetPlayerName;
  message_ = kWelcomePlayer;
  product_category_index_ = 0;
  product_selection_response_ = kNoSelection;
}

void GameState::AddToMessage(const std::string &message) {
  message_.append(message);
}

void GameState::ClearMessage() {
  message_.clear();
}

void GameState::IncrementProductCategoryIndex() {
  product_category_index_++;
}

void GameState::SetPlayerScore(const int score) {
  player_.set_score(score);
}

const std::string &GameState::get_game_step() const {
  return game_step_;
}

void GameState::set_game_step(const std::string &game_step) {
  game_step_ = game_step;
}

const std::string &GameState::get_message() const {
  return message_;
}

void GameState::set_message(const std::string &message) {
  message_ = message;
}

const Player &GameState::get_player() const {
  return player_;
}

void GameState::set_player(const Player &player) {
  player_ = player;
}

const ProductCategory &GameState::get_product_category() const {
  return product_category_;
}

void GameState::set_product_category(const ProductCategory &product_category) {
  product_category_ = product_category;
}

size_t GameState::get_product_category_index() const {
  return product_category_index_;
}

void GameState::set_product_category_index(size_t product_category_index) {
  product_category_index_ = product_category_index;
}

const Routines &GameState::get_routines() const {
  return routines_;
}

void GameState::set_routines(const Routines &routines) {
  routines_ = routines;
}

const std::string &GameState::get_product_selection_response() const {
  return product_selection_response_;
}

void GameState::set_product_selection_response(const std::string &product_selection_response) {
  product_selection_response_ = product_selection_response;
}

} // namespace skincare