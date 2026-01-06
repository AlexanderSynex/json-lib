#pragma once

#include "snx/json/details/details.hpp"

#include <regex>
#include <unordered_map>
#include <variant>

namespace snx
{
namespace json
{
namespace types
{
struct parsable
{
  virtual snx::types::string pattern () const = 0;

  bool
  is_type (snx::types::string_view str) const
  {
    return is_type_impl (str);
  }

private:
  bool
  is_type_impl (snx::types::string_view str) const
  {
    return std::regex_match (str.begin (), str.end (),
                             std::regex{ pattern () });
  }
};

struct null : public parsable
{
  snx::types::string
  pattern () const override
  {
    return R"((null))";
  }
};

struct number : public std::variant<double, int>, public parsable
{
  snx::types::string
  pattern () const override
  {
    return R"(((-)?([\d]+)(\.[\d]+)?([eE][\+-]?[\d]+)?))";
  }
};

struct string : public parsable
{
  snx::types::string
  pattern () const override
  {
    return R"(^"([^"\\]|\\["\\\/bfnr]|\\u[0-9a-eA-E]{4})*"$)";
  }
};
struct logic : public parsable
{
  snx::types::string
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
  snx::types::string
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
struct object : public std::unordered_map<snx::types::string,
                                          std::variant<object, value>>
{
};

} // namespace types
} // namespace json
} // namespace snx
