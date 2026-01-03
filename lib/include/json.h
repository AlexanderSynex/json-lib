#pragma once

#include <cstddef>
#include <optional>
#include <stdexcept>
#include <string>

#define WIP() throw std::logic_error ("Unreleased method");

#include <istream>
#include <regex>

#include <string_view>
#include <unordered_map>
#include <variant>

namespace snx
{
namespace json
{

template <typename ValueType> using optional = std::optional<ValueType>;

struct parsable
{
  bool
  is_type (std::string_view str) const
  {
    return std::regex_match (str.begin (), str.end (),
                             std::regex{ pattern () });
  }
  virtual std::string pattern () const = 0;
};

struct null : public parsable
{
  std::string
  pattern () const override
  {
    return R"((null))";
  }
};

struct number : public std::variant<double, int>, public parsable
{
  std::string
  pattern () const override
  {
    return R"(((-)?([\d]+)(\.[\d]+)?([eE][\+-]?[\d]+)?))";
  }
};

struct string : public parsable
{
  std::string
  pattern () const override
  {
    return R"(^"([^"\\]|\\["\\\/bfnr]|\\u[0-9a-eA-E]{4})*"$)";
  }
};
struct logic : public parsable
{
  std::string
  pattern () const override
  {
    return R"((true)|(false))";
  }
};

/// An array is an ordered collection of values.
/// An array begins with [left bracket and ends with ]right bracket.
/// Values are separated by ,comma.
struct array : public parsable
{
  std::string
  pattern () const override
  {
    return R"(\[[^\]]*\])";
  }
};

struct value : std::variant<string, number, array, logic, null>
{
};

/// An object is an unordered set of name/value pairs.
/// An object begins with {left brace and ends with }right brace.
/// Each name is followed by :col2on and the name/value pairs are separated by
/// ,comma.
struct object
    : public std::unordered_map<std::string, std::variant<object, value>>
{
};

namespace utils
{

enum class ErrorCode
{
  NO_ERROR = 0,
  NO_OBJECT = 1,
};

inline bool
validate (std::string_view dump, ErrorCode &ec)
{
  constexpr auto whitespaces = " \t";
  auto first_non_ws = dump.find_first_not_of (whitespaces);
  auto last_non_ws = dump.find_last_of (whitespaces);
  if (first_non_ws >= dump.size () or last_non_ws == 0)
    {
      ec = ErrorCode::NO_OBJECT;
      return false;
    }
  dump.remove_prefix (first_non_ws);
  dump.remove_suffix (last_non_ws);

  for (std::size_t lh = 0, rh = dump.size (); lh < rh; ++lh, --rh)
    {
    };
  return true;
}
}

struct json
{
  json (std::istream &&src)
  {
    auto dump = std::string{};
    for (auto line = std::string{}; std::getline (src, line);
         dump.append (line))
      ;
  }

  template <typename ValueType>
  optional<ValueType>
  operator[] (std::string_view token) const noexcept
  {
    WIP ()
    return {};
  };

private:
  optional<object> root = {};
};

} // namespace json
}; // namespace snx
