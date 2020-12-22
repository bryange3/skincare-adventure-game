//
// Created by Bryan Ge on 11/15/20.
//

#pragma once

#include <json/json.h>
#include "product_category.h"
namespace skincare {

/**
 * Represents a single skincare routine.
 */
class Routine {
 public:
  Routine() = default;
  explicit Routine(Json::Value value);

  const std::string &get_name() const;
  void set_name(const std::string &name);
  const std::vector<ProductCategory> &get_product_categories() const;
  void set_product_categories(const std::vector<ProductCategory> &product_categories);

 private:
  std::string name_;
  std::vector<ProductCategory> product_categories_;
};

} // namespace skincare