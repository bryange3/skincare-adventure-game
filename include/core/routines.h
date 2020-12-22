//
// Created by Bryan Ge on 11/15/20.
//

#pragma once

#include "routine.h"

namespace skincare {

/**
 * Represents all skincare routines.
 */
class Routines {
 public:
  Routines() = default;
  explicit Routines(const std::string &file);

  const std::vector<Routine> &get_routines() const;
  void set_routines(const std::vector<Routine> &routines);

 private:
  std::vector<Routine> routines_;
};

} // namespace skincare