//
// Created by Bryan Ge on 11/14/20.
//

#pragma once

#include <core/game_state.h>
#include "cinder/gl/gl.h"
#include <cinder/audio/Voice.h>

namespace skincare {

namespace visualizer {

/**
 * Represents the canvas that the skincare game runs in.
 */
class SkincareGameCanvas {
 public:
  SkincareGameCanvas();

  /**
   * Displays current state of the skincare game canvas.
   *
   * @param game_state current state of the game
   * @param window_width width of the game window
   * @param user_input input that user has typed
   */
  void Render(const GameState &game_state,
              const size_t window_width,
              const std::string &user_input) const;

 private:
  const size_t kMessagePositionX = 100;
  const size_t kMessagePositionY = 150;
  const std::string kGameOverImage = "gameover.png";
  const std::string kWelcomeImage = "welcome.png";
  ci::vec2 game_message_position_;

  /**
   * Displays large image.
   *
   * @param image_file filename of image to be displayed
   * @param window_width width of the game window
   */
  void RenderBigImage(const std::string &image_file,
                      const size_t window_width) const;

  /**
   * Displays game state message.
   *
   * @param message message to be displayed
   * @param message_width width of the message box
   * @param message_position position of message box
   * @param font font message is to be displayed in
   */
  void RenderMessage(const std::string &message,
                     const size_t message_width,
                     const ci::vec2 &message_position,
                     const ci::Font &font) const;

  /**
   * Displays all skincare products.
   *
   * @param products products to be displayed
   * @param window_width width of the game window
   * @param product_name_font font of the product name label
   */
  void RenderProducts(const std::vector<Product> &products,
                      const size_t window_width,
                      const ci::Font &product_name_font) const;

};

}  // namespace visualizer

}  // namespace skincare