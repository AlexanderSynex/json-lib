#pragma once

#include "snx/json/details/details.hpp"
#include "snx/json/details/types.hpp"

#include <stdexcept>
#include <string>
#include <utility>

#define WIP() throw std::logic_error ("Unreleased method");

#include <istream>
namespace snx
{
namespace json
{
struct json
{
  constexpr json () = default;
  json (json &&) = default;
  json (const json &) = default;

  [[nodiscard]] constexpr json &operator= (const json &) = default;
  [[nodiscard]] constexpr json &operator= (json &&) = default;

  json (snx::types::string_view dump){ WIP () }

  json (std::istream &&src)
      : json{ [] (std::istream &&src) -> std::string {
          auto dump = std::string{};
          for (auto line = std::string{}; std::getline (src, line);
               dump.append (line))
            ;
          return dump;
        }(std::move (src)) }
  {
  }

private:
  snx::types::optional<snx::json::types::object> root = {};
};

} // namespace json
} // namespace snx
