//
// Created by Ahmed Abou Aliaa on 05.11.20.
//

#include <iostream>

#include "support/CommandLine.h"

namespace alif::support::cli {

///
/// \param vm variables map
/// \param for_what requiring option
/// \param required_option required option
void dependant_options(boost::program_options::variables_map const &vm,
                       std::string const &for_what,
                       std::string const &required_option) {
  if ((vm.count(for_what) != 0U) && !vm[for_what].defaulted()) {
    if (vm.count(required_option) == 0 || vm[required_option].defaulted()) {
      auto msg = fmt::format("Option '{}' requires option '{}'.", for_what,
                             required_option);
      throw std::logic_error(msg);
    }
  }
}

///
/// \param vm variables map
/// \param opt1 conflicting option 1
/// \param opt2 conflicting option 2
void conflicting_options(boost::program_options::variables_map const &vm,
                         std::string const &opt1, std::string const &opt2) {
  if ((vm.count(opt1) != 0U) && !vm[opt1].defaulted() &&
      (vm.count(opt2) != 0U) && !vm[opt2].defaulted()) {
    auto msg = fmt::format("Conflicting options '{}' and '{}'.", opt1, opt2);
    throw std::logic_error(msg);
  }
}

///
/// \param desc holds description of supported args
/// \param env holds the vcid string
void print_usage(boost::program_options::options_description const &desc,
                 ENV * /*env*/) {
  std::cout << desc << std::endl;
}

///
/// \param desc holds description of supported args
/// \param env holds the vcid string
void print_help(boost::program_options::options_description const &desc,
                ENV *env) {
  print_usage(desc, env);
}

///
/// \param desc holds description of supported args
/// \param env holds the vcid string
void print_version() { std::cout << "VERSION: 3.0" << std::endl; }

void print_parsed_tokens(po::basic_parsed_options<char> const &parsed_opts) {
  for (const auto &opt : parsed_opts.options) {
    std::string tmp{};
    for (const auto &token : opt.original_tokens) {
      tmp += token;
      tmp += " ";
    }
    tmp.pop_back(); // last space
    fmt::print("{}\n", tmp);
  }
}

auto check_string_values(std::vector<std::string> allowed,
                         std::string_view value, std::string_view opt) {

  if (std::find(allowed.begin(), allowed.end(), value) != allowed.end()) {
    return;
  }

  auto message = fmt::format("value '{}' disallowed for option \"{}\". try "
                             "--help for more detail\n",
                             value, opt);
  throw std::logic_error(message);
}

auto checkString() {

  static auto checkString = [](std::vector<std::string> allowed,
                               std::string_view opt) {
    return [allowed, opt](auto value) {
      check_string_values(allowed, value, opt);
    };
  };

  return checkString;
}

auto addConflicts() {

  static auto addConflicts = [](std::vector<std::string> const &conflicts,
                                std::string_view name, auto *args) {
    return [name, conflicts, args]([[maybe_unused]] auto v) {
      for (const auto &conflict : conflicts) {
        args->conflict_map.insert(std::make_pair(name, conflict));
      }
    };
  };

  return addConflicts;
}

auto addDependencies() {

  static auto addDependencies = [](std::vector<std::string> const &dependencies,
                                   std::string_view name, auto *args) {
    return [name, dependencies, args]([[maybe_unused]] auto value) {
      for (const auto &dependency : dependencies) {
        args->dependency_map.insert(std::make_pair(name, dependency));
      }
    };
  };

  return addDependencies;
}
} // namespace alif::support::cli