//
// Created by Bryan Ge on 11/14/20.
//

#include "../../include/core/game.h"
#include "../../include/core/constants.h"

#include <utility>
#include <iostream>

namespace skincare {

using skincare::Routines;
using skincare::Routine;

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::to_string;

Game::Game(const string &file) {
  routines_ = Routines(file);
}

void Game::Play() {
  do {
    string input = TakeCommandLineInput();
    UpdateGame(input);
  } while (game_state_.get_game_step() != kGameStepGameEnd);
}

void Game::UpdateGame(const string &input) {
  const string &game_step = game_state_.get_game_step();
  if (game_step == kGameStepGetPlayerName) {
    SetPlayerName(input);
  } else if (game_step == kGameStepGameIntro) {
    RoutineSelection(input);
  } else if (game_step == kGameStepChooseProduct) {
    ProductSelection(input);
  } else if (game_step == kGameStepFinal) {
    game_state_.set_game_step(kGameStepGameEnd);
  }
}

std::string Game::TakeCommandLineInput() {
  cout << game_state_.get_message();
  string input;
  getline(cin, input);
  return input;
}

void Game::RoutineSelection(const string &selected_routine) {
  if (IsValidRoutine(selected_routine)) {
    // sets the first product category
    game_state_.set_product_category(selected_routine_.get_product_categories().at(
        game_state_.get_product_category_index()));
    game_state_.set_game_step(kGameStepChooseProduct);
    game_state_.ClearMessage();
    HandleProductMessage(game_state_.get_product_category());
  } else {
    game_state_.set_message(kInvalidRoutine);
    HandleRoutineMessage();
  }
}

bool Game::IsValidRoutine(const std::string &selected_routine) {
  // search for the provided routine using its name
  for (const auto &routine : routines_.get_routines()) {
    if (selected_routine == routine.get_name()) {
      game_state_.set_message(
          "\n" + kNiceRoutine + routine.get_name() + ".\n\n");
      selected_routine_ = routine;
      return true;
    }
  }
  return false;
}

void Game::HandleRoutineMessage() {
  game_state_.AddToMessage(kRoutineIntro);
  const vector<Routine> &routines = routines_.get_routines();
  for (size_t i = 0; i < routines.size(); i++) {
    game_state_.AddToMessage(
        std::to_string(i + 1) + ". " + routines.at(i).get_name() + "\n");
  }
  game_state_.AddToMessage("\n" + kPromptForRoutine);
}

void Game::HandleProductMessage(const ProductCategory &product_category) {
  game_state_.AddToMessage(kProductIntroStart);
  game_state_.AddToMessage(product_category.get_type());
  game_state_.AddToMessage(kProductIntroEnd);
  const vector<Product> &products = product_category.get_products();
  for (size_t i = 0; i < products.size(); i++) {
    game_state_.AddToMessage(
        std::to_string(i + 1) + ". " + products.at(i).get_name() + "\n");
  }
  game_state_.AddToMessage(kPromptForProducts);
}

void Game::ProductSelection(const string &selected_product) {
  if (IsValidProduct(selected_product, game_state_.get_product_category())) {
    if (IsAtFinalProductCategory()) {
      game_state_.set_game_step(kGameStepFinal);
      Outro();
    } else {
      game_state_.IncrementProductCategoryIndex();
      game_state_.set_product_category(selected_routine_.get_product_categories().at(
          game_state_.get_product_category_index()));
      HandleProductMessage(game_state_.get_product_category());
    }
  } else {
    game_state_.set_message(kInvalidProduct);
    HandleProductMessage(game_state_.get_product_category());
  }
}

bool Game::IsValidProduct(const string &selected_product,
                          const ProductCategory &product_category) {
  // search for the provided routine using its name
  for (const auto &product : product_category.get_products()) {
    if (selected_product == product.get_name()) {
      player_.AddPoints(product.get_points());
      if (IsGoodProduct(product.get_points())) {
        game_state_.set_product_selection_response(kGoodProduct);
      } else {
        game_state_.set_product_selection_response(kBadProduct);
      }

      game_state_.SetPlayerScore(player_.get_score());
      game_state_.set_message(product.get_message() + "\n");
      game_state_.AddToMessage(kEarnedStart);
      game_state_.AddToMessage(to_string(product.get_points()));
      game_state_.AddToMessage(kEarnedEnd + kCurrentScoreIntro);
      game_state_.AddToMessage(to_string(player_.get_score()) + "\n\n");
      return true;
    }
  }
  game_state_.set_product_selection_response(kNoSelection);
  return false;
}

void Game::SetPlayerName(const std::string &name) {
  player_.set_name(name);
  game_state_.set_game_step(kGameStepGameIntro);
  game_state_.set_message(kGameExplanationStart + name + kGameExplanationEnd);
  game_state_.set_routines(routines_);
  HandleRoutineMessage();
}

void Game::Outro() {
  game_state_.AddToMessage(kOutroStart);
  game_state_.AddToMessage(to_string(game_state_.get_player().get_score()));
  game_state_.AddToMessage(kOutroEnd);
}

bool Game::IsAtFinalProductCategory() {
  return game_state_.get_product_category_index()
      == selected_routine_.get_product_categories().size() - 1;
}

const GameState &Game::get_game_state() const {
  return game_state_;
}

const Routines &Game::get_routines() const {
  return routines_;
}

const Routine &Game::get_selected_routine() const {
  return selected_routine_;
}

const Player &Game::get_player() const {
  return player_;
}

bool Game::IsGoodProduct(const int points) {
  return points > 0;
}

} // namespace skincare
