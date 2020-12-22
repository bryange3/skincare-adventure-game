//
// Created by Bryan Ge on 11/14/20.
//

#include <catch2/catch.hpp>
#include <core/game.h>
#include <core/constants.h>

using skincare::Routine;
using skincare::ProductCategory;
using skincare::Product;
using skincare::Game;
using std::vector;

const std::string
    kTestSkincareProducts = "../src/resources/test_skincare_products.json";

TEST_CASE("Load game data") {
  Game game(kTestSkincareProducts);
  const vector<Routine> &routines = game.get_routines().get_routines();
  REQUIRE(routines.size() == 2);

  const Routine &bougie_evening = routines.at(0);
  const Routine &simple_evening = routines.at(1);
  REQUIRE(bougie_evening.get_name() == "Bougie Evening Skincare Routine");
  REQUIRE(simple_evening.get_name() == "Simple Evening Skincare Routine");

  const vector<ProductCategory>
      &bougie_categories = bougie_evening.get_product_categories();
  REQUIRE(bougie_categories.size() == 2);

  const ProductCategory &first_cleanser = bougie_categories.at(0);
  REQUIRE(first_cleanser.get_type() == "first cleanser");

  const vector<Product> &first_cleansers = first_cleanser.get_products();
  REQUIRE(first_cleansers.size() == 2);
  REQUIRE(
      first_cleansers.at(0).get_name() == "Farmacy Green Clean Cleansing Balm");
  REQUIRE(first_cleansers.at(0).get_points() == 10);
  REQUIRE(first_cleansers.at(0).get_image_url()
              == "https://www.sephora.com/productimages/sku/s2111425-main-zoom."
                  + std::string("jpg?pb=2020-03-sephora-clean-2019&imwidth=")
                  + "300");
  REQUIRE(first_cleansers.at(0).get_message()
              == "Great choice! This is an all-time favorite cleansing balm "
                  + std::string(
                      "in the skincare community and makes for a great ")
                  + "first cleanse.");
  REQUIRE(first_cleansers.at(1).get_name() == "Neutrogena Makeup Wipes");
  REQUIRE(first_cleansers.at(1).get_points() == -10);
  REQUIRE(first_cleansers.at(1).get_image_url()
              == "https://images.ulta.com/is/image/Ulta/2298522");
  REQUIRE(first_cleansers.at(1).get_message()
              == "Uh oh! Makeup wipes are very harsh and stripping to the skin."
                  + std::string(" There's also a good chance that when you ")
                  + "use them you don't completely remove your makeup.");

  const ProductCategory &water_cleanser = bougie_categories.at(1);
  REQUIRE(water_cleanser.get_type() == "water-based cleanser");

  const vector<Product> &water_cleansers = water_cleanser.get_products();
  REQUIRE(water_cleansers.size() == 1);
  REQUIRE(water_cleansers.at(0).get_name()
              == "KraveBeauty Matcha Hemp Hydrating Cleanser");
  REQUIRE(water_cleansers.at(0).get_points() == 10);
  REQUIRE(water_cleansers.at(0).get_image_url()
              == "https://cdn.shopify.com/s/files/1/2090/8057/products/"
                  + std::string("KRAVE_2-1_1_1024x.jpg?v=1569098046"));
  REQUIRE(water_cleansers.at(0).get_message()
              == "Excellent choice! This is the perfect cleanser to remove "
                  + std::string("impurities from the skin while keeping the ")
                  + "skin hydrated.");

  const vector<ProductCategory>
      &simple_categories = simple_evening.get_product_categories();
  REQUIRE(simple_categories.size() == 2);

  const ProductCategory &cleanser = simple_categories.at(0);
  REQUIRE(cleanser.get_type() == "cleanser");

  const vector<Product> &cleansers = cleanser.get_products();
  REQUIRE(cleansers.size() == 1);
  REQUIRE(cleansers.at(0).get_name() == "Head & Shoulders Shampoo");
  REQUIRE(cleansers.at(0).get_points() == -10);
  REQUIRE(cleansers.at(0).get_image_url()
              == "https://images-na.ssl-images-amazon.com/images/I/81oBAm2GYxL."
                  + std::string("_SL1500_.jpg"));
  REQUIRE(cleansers.at(0).get_message()
              == "Oh no! Please don't use shampoo as your cleanser. This can be"
                  + std::string(" incredibly stripping to the skin."));

  const ProductCategory &moisturizer = simple_categories.at(1);
  REQUIRE(moisturizer.get_type() == "moisturizer");

  const vector<Product> &moisturizers = moisturizer.get_products();
  REQUIRE(moisturizers.size() == 1);
  REQUIRE(
      moisturizers.at(0).get_name() == "Clean & Clear Dual Action Moisturizer");
  REQUIRE(moisturizers.at(0).get_points() == 4);
  REQUIRE(moisturizers.at(0).get_image_url()
              == "https://www.cleanandclear.ca/sites/cleanandclear_ca/files"
                  + std::string("/product-images/ess-dam.png"));
  REQUIRE(moisturizers.at(0).get_message()
              == "This is not such a great choice because it contains fragrance"
                  + std::string(" and could be irritating."));
}

TEST_CASE("Game input handling") {
  Game game(kTestSkincareProducts);
  REQUIRE(game.get_game_state().get_game_step() == kGameStepGetPlayerName);

  SECTION("User name") {
    game.UpdateGame("Bryan Ge");
    REQUIRE(game.get_player().get_name() == "Bryan Ge");
    REQUIRE(game.get_player().get_score() == 0);
    REQUIRE(game.get_game_state().get_game_step() == kGameStepGameIntro);
  }

  SECTION("Routine selection") {
    game.UpdateGame("Bryan Ge");

    SECTION("Proper selection") {
      game.UpdateGame("Bougie Evening Skincare Routine");
      REQUIRE(game.get_selected_routine().get_name() == "Bougie Evening"
          + std::string(" Skincare Routine"));
      REQUIRE(game.get_game_state().get_game_step() == kGameStepChooseProduct);
      REQUIRE(game.get_game_state().get_message() == "Here are the first "
          + std::string("cleansers available for you:\n1. Farmacy Green Clean ")
          + "Cleansing Balm\n2. Neutrogena Makeup Wipes\n\nSelect which "
          + "product you would like to use: ");
    }

    SECTION("Improper selection") {
      game.UpdateGame("CS 126");
      REQUIRE(game.get_selected_routine().get_name() != "CS 126");
      REQUIRE(game.get_game_state().get_game_step() == kGameStepGameIntro);
      REQUIRE(game.get_game_state().get_message() == "The routine you typed is "
          + std::string("invalid. Please try again.\n\nHere are the skincare ")
          + "routines you can choose from:\n1. Bougie Evening Skincare "
          + "Routine\n2. Simple Evening Skincare Routine\n\nSelect which "
          + "routine you would like to do tonight: ");
    }
  }

  SECTION("Products selection") {
    game.UpdateGame("Bryan Ge");
    game.UpdateGame("Bougie Evening Skincare Routine");

    // player initially has a score of 0
    REQUIRE(game.get_game_state().get_player().get_score() == 0);

    SECTION("Proper selection") {
      SECTION("Increase in points") {
        game.UpdateGame("Farmacy Green Clean Cleansing Balm");
        REQUIRE(game.get_game_state().get_player().get_score() == 10);
        REQUIRE(game.get_game_state().get_message() == "Great choice! This is "
            + std::string("an all-time favorite cleansing balm in the ")
            + "skincare community and makes for a great first cleanse.\n"
            + "You have earned 10 points.\n\nCURRENT SCORE: 10\n\nHere are"
            + " the water-based cleansers available for you:\n1. "
            + "KraveBeauty Matcha Hemp Hydrating Cleanser\n\nSelect which "
            + "product you would like to use: ");
      }

      SECTION("Decrease in points") {
        game.UpdateGame("Neutrogena Makeup Wipes");
        REQUIRE(game.get_game_state().get_player().get_score() == -10);
        REQUIRE(game.get_game_state().get_message() == "Uh oh! Makeup wipes are"
            + std::string(" very harsh and stripping to the skin. ")
            + "There's also a good chance that when you use them you don't "
            + "completely remove your makeup.\nYou have earned -10 points.\n\n"
            + "CURRENT SCORE: -10\n\nHere are the water-based cleansers "
            + "available for you:\n1. KraveBeauty Matcha Hemp Hydrating "
            + "Cleanser\n\nSelect which product you would like to use: ");
      }
    }

    SECTION("Improper selection") {
      game.UpdateGame("CS 126");

      // no change in initial score of 0
      REQUIRE(game.get_game_state().get_player().get_score() == 0);
      REQUIRE(game.get_game_state().get_message() == "The product you selected "
          + std::string("is invalid. Please try again.\n\nHere are the first ")
          + "cleansers available for you:\n1. Farmacy Green Clean Cleansing "
          + "Balm\n2. Neutrogena Makeup Wipes\n\nSelect which product you would"
          + " like to use: ");
    }
  }
}