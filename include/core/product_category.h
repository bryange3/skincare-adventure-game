//
// Created by Bryan Ge on 11/15/20.
//

#pragma once

#include <string>
#include <vector>
#include <json/json.h>
#include "product.h"

namespace skincare {

/**
 * Represents a product category. (ex. moisturizer, serum, oil)
 */
class ProductCategory {
 public:
  ProductCategory() = default;
  explicit ProductCategory(Json::Value value);

  const std::string &get_type() const;
  void set_type(const std::string &type);
  const std::vector<Product> &get_products() const;
  void set_products(const std::vector<Product> &products);

 private:
  std::string type_;
  std::vector<Product> products_;
};

} // namespace skincare
