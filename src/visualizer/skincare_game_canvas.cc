//
// Created by Bryan Ge on 11/14/20.
//

#include <visualizer/skincare_game_canvas.h>
#include <cinder/app/AppBase.h>
#include "core/constants.h"

namespace skincare {

namespace visualizer {

using glm::vec2;
using std::vector;

SkincareGameCanvas::SkincareGameCanvas() {
  game_message_position_ = ci::vec2(kMessagePositionX, kMessagePositionY);
}

void SkincareGameCanvas::Render(const GameState &game_state,
                                const size_t window_width,
                                const std::string &user_input) const {
  const std::string &game_step = game_state.get_game_step();

  // draw game title
  ci::gl::drawStringCentered("Choose Your Skincare!",
                             ci::vec2(window_width / 2, 75),
                             ci::Color("black"),
                             ci::Font("Avenir Heavy", 24));

  // render game message/prompt
  size_t game_message_width = 900;
  const std::string &game_message = game_state.get_message();
  ci::Font game_font = ci::Font("Avenir", 14);
  RenderMessage(game_message,
                game_message_width,
                game_message_position_,
                game_font);

  // render user's input
  if (game_step != kGameStepFinal) {
    size_t user_input_width = 300;
    ci::Font user_input_font = ci::Font("Avenir Heavy", 16);
    ci::vec2 user_input_position
        (game_message_position_.x + game_message_width,
         game_message_position_.y);
    RenderMessage("YOUR INPUT: " + user_input,
                  user_input_width,
                  user_input_position,
                  user_input_font);
  }

  if (game_step == kGameStepGetPlayerName || game_step == kGameStepGameIntro) {
    RenderBigImage(kWelcomeImage, window_width);
  } else if (game_step == kGameStepChooseProduct) {
    const vector<Product>
        &products = game_state.get_product_category().get_products();
    RenderProducts(products, window_width, game_font);
  } else if (game_step == kGameStepFinal) {
    ci::gl::Texture2dRef texture;
    ci::ImageSourceRef image;
    image = ci::loadImage(ci::app::loadAsset(kGameOverImage));
    texture = ci::gl::Texture2d::create(image);
    ci::Rectf drawRect(size_t(window_width / 2) - 400,
                       game_message_position_.y + 200,
                       size_t(window_width / 2) + 400,
                       game_message_position_.y + 650);
    ci::gl::draw(texture, drawRect);
  }
}

void SkincareGameCanvas::RenderMessage(const std::string &message,
                                       const size_t message_width,
                                       const ci::vec2 &message_position,
                                       const ci::Font &font) const {
  // https://forum.libcinder.org/topic/text-box-with-transparent-text
  ci::TextBox message_display =
      ci::TextBox().alignment(ci::TextBox::LEFT).text(message).font(
          font).size(ci::ivec2(message_width, ci::TextBox::GROW));
  message_display.setColor("black");
  message_display.setPremultiplied(true);
  ci::gl::Texture2dRef
      message_texture = ci::gl::Texture2d::create(message_display.render());
  ci::gl::draw(message_texture, message_position);
}

void SkincareGameCanvas::RenderProducts(const vector<Product> &products,
                                        const size_t window_width,
                                        const ci::Font &product_name_font) const {
  size_t start_image_y = game_message_position_.y + 300;
  size_t image_width = 250;
  size_t gap_between_images = 100;
  const size_t num_products = products.size();
  size_t images_section_width =
      (num_products * image_width) + ((num_products - 1) * gap_between_images);
  size_t start_image_x = (window_width - images_section_width) / 2;
  size_t end_image_x = start_image_x + image_width;

  // render product images and labels
  for (const auto &product : products) {
    // https://mottosso.gitbooks.io/cinder/content/book/cinder/loadUrl.html
    ci::gl::Texture2dRef texture;
    ci::ImageSourceRef image;

    // load product image from URL
    try {
      image = ci::loadImage(ci::loadUrl(product.get_image_url()));
    } catch (cinder::ImageIoExceptionFailedLoad &e) {
      std::cout << product.get_image_url() << std::endl;
    }

    size_t end_image_y = start_image_y + image_width + 100;
    texture = ci::gl::Texture2d::create(image);
    ci::Rectf drawRect(start_image_x,
                       start_image_y,
                       end_image_x,
                       end_image_y);
    ci::gl::draw(texture, drawRect);
    ci::gl::drawStringCentered(product.get_name(),
                               ci::vec2(start_image_x + image_width / 2,
                                        end_image_y + 10),
                               ci::Color("black"),
                               product_name_font);

    start_image_x = start_image_x + image_width + gap_between_images;
    end_image_x = end_image_x + image_width + gap_between_images;
  }
}

void SkincareGameCanvas::RenderBigImage(const std::string &image_file,
                                        const size_t window_width) const {
  ci::gl::Texture2dRef texture;
  ci::ImageSourceRef image;
  image = ci::loadImage(ci::app::loadAsset(image_file));
  texture = ci::gl::Texture2d::create(image);
  ci::Rectf drawRect(size_t(window_width / 2) - 400,
                     game_message_position_.y + 200,
                     size_t(window_width / 2) + 400,
                     game_message_position_.y + 650);
  ci::gl::draw(texture, drawRect);
}

}  // namespace visualizer

}  // namespace skincare