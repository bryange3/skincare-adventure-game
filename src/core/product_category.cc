//
// Created by Bryan Ge on 11/15/20.
//

#include "core/product_category.h"

#include <utility>

namespace skincare {

ProductCategory::ProductCategory(Json::Value value) {
  type_ = value["type"].asString();
  Json::Value products = value["products"];

  for (const Json::Value &product : products) {
    products_.emplace_back(product);
  }
}

const std::string &ProductCategory::get_type() const {
  return type_;
}

void ProductCategory::set_type(const std::string &type) {
  type_ = type;
}

const std::vector<Product> &ProductCategory::get_products() const {
  return products_;
}

void ProductCategory::set_products(const std::vector<Product> &products) {
  products_ = products;
}

} // namespace skincare