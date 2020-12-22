//
// Created by Bryan Ge on 11/15/20.
//

#include "core/routine.h"

#include <utility>

namespace skincare {

Routine::Routine(Json::Value value) {
  name_ = value["name"].asString();
  Json::Value product_categories = value["product categories"];

  for (const Json::Value &product_category : product_categories) {
    product_categories_.emplace_back(product_category);
  }
}

const std::string &Routine::get_name() const {
  return name_;
}

void Routine::set_name(const std::string &name) {
  name_ = name;
}

const std::vector<ProductCategory> &Routine::get_product_categories() const {
  return product_categories_;
}

void Routine::set_product_categories(const std::vector<ProductCategory> &product_categories) {
  product_categories_ = product_categories;
}

} // namespace skincare