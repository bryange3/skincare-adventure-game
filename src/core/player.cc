//
// Created by Bryan Ge on 11/28/20.
//

#include "core/player.h"

namespace skincare {

void Player::AddPoints(const int points) {
  score_ += points;
}

const std::string &Player::get_name() const {
  return name_;
}

void Player::set_name(const std::string &name) {
  name_ = name;
}

int Player::get_score() const {
  return score_;
}

void Player::set_score(int score) {
  score_ = score;
}

} // namespace skincare