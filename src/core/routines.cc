//
// Created by Bryan Ge on 11/15/20.
//

#include <fstream>
#include <utility>
#include "core/routines.h"
#include "json/json.h"

namespace skincare {

Routines::Routines(const std::string &file) {
  // https://stackoverflow.com/questions/13935364/how-to-read-a-json-file-into-a-c-string/13935499
  std::ifstream is(file);
  Json::Value value;
  is >> value;

  // https://stackoverflow.com/questions/44442932/iterate-over-an-array-of-json-objects-with-jsoncpp
  Json::Value routines = value["routines"];
  for (const Json::Value &routine : routines) {
    routines_.emplace_back(routine);
  }
}

const std::vector<Routine> &Routines::get_routines() const {
  return routines_;
}

void Routines::set_routines(const std::vector<Routine> &routines) {
  routines_ = routines;
}

} // namespace skincare