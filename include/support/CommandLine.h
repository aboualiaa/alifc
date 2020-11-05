//
// Created by Ahmed Abou Aliaa on 05.11.20.
//

#ifndef SUPPORT_COMMANDLINE_H
#define SUPPORT_COMMANDLINE_H

#include <fstream>
#include <iostream>

#include <boost/algorithm/string.hpp>
#include <boost/program_options.hpp>
#include <fmt/format.h>
#include <spdlog/spdlog.h>

namespace alif::support::cli {

namespace pocl = boost::program_options::command_line_style;
namespace po = boost::program_options;

void conflicting_options(boost::program_options::variables_map const &vm,
                         std::string const &opt1, std::string const &opt2);

void dependant_options(boost::program_options::variables_map const &vm,
                       std::string const &for_what,
                       std::string const &required_option);

struct CMDARGS {
  explicit CMDARGS(std::vector<char const *> args) { raw = std::move(args); }

  void check_conflicts(po::variables_map const &vm) {
    for (auto const &[key, val] : conflict_map) {
      conflicting_options(vm, key, val);
    }
  }

  void check_dependencies(po::variables_map const &vm) {
    for (auto const &[key, val] : dependency_map) {
      dependant_options(vm, key, val);
    }
  }

  auto get_raw_array() -> char const ** { return raw.data(); }

  auto get_raw_size() -> size_t { return raw.size(); }

public:
private:
  std::vector<char const *> raw;
  std::multimap<std::string, std::string> conflict_map;
  std::multimap<std::string, std::string> dependency_map;
};

struct ENV {};

void print_usage(boost::program_options::options_description const &desc,
                 ENV *env);

void print_help(boost::program_options::options_description const &desc,
                ENV *env);

void print_version();

template <typename T>
auto check_vector_range(const std::vector<T> &vector, std::string_view opt,
                        size_t lower, size_t upper = 0) -> bool {
  upper = upper == 0 ? lower : upper;
  if (lower > upper) {
    auto message = fmt::format("lower bound '{}' must be less than upper bound "
                               "'{}' for argument \"{}\".\n",
                               lower, upper, opt);
    throw std::logic_error(message);
  }
  if (vector.size() < lower || vector.size() > upper) {
    auto message =
        fmt::format("given values for argument \"{}\" not within range: "
                    "have '{}', expected value "
                    "in range '{}...{}'.\n",
                    opt, vector.size(), lower, upper);
    throw std::logic_error(message);
  }
  return true;
}

template <typename T>
auto check_value_range(T const value, std::string_view opt, T lower,
                       T upper = 0) -> bool {
  upper = upper == 0 ? lower : upper;
  if (lower > upper) {
    auto message = fmt::format("lower bound '{}' must be less than upper bound "
                               "'{}' for argumet \"{}\".\n",
                               lower, upper, opt);
    throw std::logic_error(message);
  }
  if (value < lower || value > upper) {
    auto message =
        fmt::format("given values for argument \"{}\" not within range: "
                    "have '{}', expected value "
                    "in range'{}...{}'.\n",
                    opt, value, lower, upper);
    throw std::logic_error(message);
  }
  return true;
}

template <typename T>
auto check_value(T const value, T comp, std::string_view opt,
                 std::function<bool(T, T)> fn) -> bool {
  if (!fn(value, comp)) {
    auto message = fmt::format("value '{}' disallowed for option \"{}\". try "
                               "--help for more detail\n",
                               value, opt);
    throw std::logic_error(message);
  }
  return true;
}

auto check_string_values(std::vector<std::string> allowed,
                         std::string_view value, std::string_view opt);

const auto checkSize = [](auto opt, size_t min, size_t max = 0) {
  return [opt, min, max](auto v) { check_vector_range(v, opt, min, max); };
};

const auto checkValue =
    [](auto min, auto opt,
       std::function<bool(decltype(min), decltype(min))> fn) {
      return [min, opt, fn](auto value) { check_value(value, min, opt, fn); };
    };

const auto checkRange = [](auto min, auto max, auto opt) {
  return
      [min, opt, max](auto value) { check_value_range(value, opt, min, max); };
};

const auto allocateExternalString = [](char **var) mutable {
  return [var](std::string value) mutable {
    *var = static_cast<char *>(calloc(value.length() + 1, sizeof(char)));
    memmove(*var, value.data(), value.length());
  };
};

auto checkString();
auto addConflicts();
auto addDependencies();

// program option style
constexpr auto po_style =
    static_cast<unsigned>(pocl::allow_short) | pocl::short_allow_adjacent |
    pocl::short_allow_next | pocl::allow_long | pocl::long_allow_adjacent |
    pocl::long_allow_next | pocl::allow_sticky | pocl::allow_dash_for_short |
    pocl::allow_long_disguise;

void print_parsed_tokens(po::basic_parsed_options<char> const &parsed_opts);

} // namespace alif::support::cli

#endif // SUPPORT_COMMANDLINE_H
