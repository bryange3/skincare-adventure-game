//
// Created by Bryan Ge on 11/15/20.
//

#include "core/product.h"
#include <utility>

namespace skincare {

Product::Product(Json::Value value) {
  name_ = value["name"].asString();
  points_ = value["points"].asInt();
  image_url_ = value["image url"].asString();
  message_ = value["message"].asString();
}

const std::string &Product::get_name() const {
  return name_;
}

void Product::set_name(const std::string &name) {
  name_ = name;
}

int Product::get_points() const {
  return points_;
}

void Product::set_points(int points) {
  points_ = points;
}

const std::string &Product::get_image_url() const {
  return image_url_;
}

void Product::set_image_url(const std::string &image_url) {
  image_url_ = image_url;
}

const std::string &Product::get_message() const {
  return message_;
}

void Product::set_message(const std::string &message) {
  message_ = message;
}

} // namespace skincare