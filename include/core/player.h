//
// Created by Bryan Ge on 11/28/20.
//

#pragma once

#include <string>

namespace skincare {

/**
 * Represents player/user.
 */
class Player {
 public:
  /**
   * Creates initial player object with starting score of 0.
   *
   * @param starting_score player's starting score value
   */
  explicit Player(int starting_score = 0) : score_(starting_score) {}

  /**
   * Adds points to player's score.
   *
   * @param points points to be added to the player's score
   */
  void AddPoints(const int points);

  const std::string &get_name() const;
  void set_name(const std::string &name);
  int get_score() const;
  void set_score(int score);

 private:
  std::string name_;
  int score_;
};

} // namespace skincare