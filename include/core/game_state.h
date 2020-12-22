//
// Created by Bryan Ge on 11/28/20.
//

#pragma once

#include <string>
#include <vector>
#include "player.h"
#include "product.h"
#include "routine.h"
#include "routines.h"

namespace skincare {

/**
 * Represents state of the game.
 */
class GameState {
 public:
  GameState();

  /**
   * Adds to the message.
   *
   * @param message message to be added to the existing message
   */
  void AddToMessage(const std::string &message);

  /**
   * Clear the message.
   */
  void ClearMessage();

  /**
   * Increments the product category index. Used to move the game state to the
   * next product category.
   */
  void IncrementProductCategoryIndex();

  /**
   * Sets the player score.
   *
   * @param score score to be set
   */
  void SetPlayerScore(const int score);

  const std::string &get_game_step() const;
  void set_game_step(const std::string &game_step);
  const std::string &get_message() const;
  void set_message(const std::string &message);
  const Player &get_player() const;
  void set_player(const Player &player);
  const ProductCategory &get_product_category() const;
  void set_product_category(const ProductCategory &product_category);
  size_t get_product_category_index() const;
  void set_product_category_index(size_t product_category_index);
  const Routines &get_routines() const;
  void set_routines(const Routines &routines);

 private:
  std::string game_step_; // step of the game the player is currently in
  std::string message_;
  ProductCategory product_category_;
  size_t product_category_index_;
  std::string product_selection_response_;
 public:
  const std::string &get_product_selection_response() const;
  void set_product_selection_response(const std::string &product_selection_response);
 private:
  Routines routines_;
  Player player_;
};

} // namespace skincare