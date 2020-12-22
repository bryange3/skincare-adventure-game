//
// Created by Bryan Ge on 11/15/20.
//

#pragma once

#include <string>
#include <json/json.h>

namespace skincare {

/**
 * Represents a single skincare product.
 */
class Product {
 public:
  explicit Product(Json::Value value);

  const std::string &get_name() const;
  void set_name(const std::string &name);
  int get_points() const;
  void set_points(int points);
  const std::string &get_image_url() const;
  void set_image_url(const std::string &image_url);
  const std::string &get_message() const;
  void set_message(const std::string &message);

 private:
  std::string name_;
  int points_;
  std::string image_url_;
  std::string message_;
};

} // namespace skincare