//
// Created by Bryan Ge on 11/14/20.
//

#pragma once

#include "routines.h"
#include "player.h"
#include "game_state.h"

namespace skincare {

/**
 * Holds gameplay components.
 */
class Game {
 public:
  Game() = default;

  /**
   * Creates game based on game data file.
   *
   * @param file name of data file used for gameplay
   */
  Game(const std::string &file);

  /**
   * Runs gameplay.
   */
  void Play();

  /**
   * Updates the game according to the provided input.
   *
   * @param input user's input
   */
  void UpdateGame(const std::string &input);

  const GameState &get_game_state() const;
  const Routines &get_routines() const;
  const Routine &get_selected_routine() const;
  const Player &get_player() const;

 private:
  Routines routines_;
  Routine selected_routine_; // routine the user selects to do
  Player player_;
  GameState game_state_;

  /**
   * Handles command line user input.
   *
   * @return the user's input
   */
  std::string TakeCommandLineInput();

  /**
   * Sets player's name.
   *
   * @param name player name
   */
  void SetPlayerName(const std::string &name);

  /**
   * Handles user's routine selection. Updates game state accordingly.
   *
   * @param selected_routine name of routine the user has selected
   */
  void RoutineSelection(const std::string &selected_routine);

  /**
   * Updates game state message with routines information.
   */
  void HandleRoutineMessage();

  /**
   * Checks if routine selected is a valid routine.
   *
   * @param selected_routine name of routine selected to be checked
   * @return true if routine is valid and false if the routine is not valid
   */
  bool IsValidRoutine(const std::string &selected_routine);

  /**
   * Handles user's product selection. Updates game state accordingly.
   *
   * @param selected_product name of product the user has selected
   */
  void ProductSelection(const std::string &selected_product);

  /**
   * Checks if product is good.
   *
   * @param points points the product gives
   * @return true if the product is good (positive points) and false if not
   *         (negative points)
   */
  bool IsGoodProduct(const int points);

  /**
   * Checks if the selected product is a valid selection.
   *
   * @param selected_product name of product the user has selected
   * @param product_category product category the user is selecting from
   * @return true if product is a valid choice and false if not
   */
  bool IsValidProduct(const std::string &selected_product,
                      const ProductCategory &product_category);

  /**
   * Updates game state message with products information.
   */
  void HandleProductMessage(const ProductCategory &product_category);

  /**
   * Checks if user is at the final product category in the gameplay.
   *
   * @return true when at the final product category and false if not
   */
  bool IsAtFinalProductCategory();

  /**
   * Prepares end messages of game.
   */
  void Outro();
};

} // namespace skincare