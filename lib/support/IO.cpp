//
// Created by Ahmed Abou Aliaa on 05.11.20.
//

#include <fstream>
#include <fmt/format.h>

namespace alif::support::io {

auto checkFileReadable() {
  static auto checkFileReadable = [](std::string_view file_name) {
    std::ifstream fptmp(file_name.data());
    if (!fptmp.is_open()) {
      auto message =
          fmt::format("ERROR: could not open {} for reading\n", file_name);
      throw std::logic_error(message);
    }
    fptmp.close();
  };

  return checkFileReadable;
}

auto checkFileWriteable() {
  static auto checkFileWriteable = [](std::string_view file_name) {
    std::ofstream fptmp(file_name.data());
    if (!fptmp.is_open()) {
      auto message =
          fmt::format("ERROR: could not open {} for writing\n", file_name);
      throw std::logic_error(message);
    }
    fptmp << "0\n";
    fptmp.close();
  };

  return checkFileReadable;
}

} // namespace alif::support::io
