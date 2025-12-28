#pragma once

#include <regex>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <variant>

namespace snx
{
namespace json
{

struct parsable
{
  bool
  is_type (std::string_view str) const
  {
    return std::regex_match (str.begin (), str.end (),
                             std::regex{ pattern () });
  }
  virtual const char *pattern () const = 0;
};

struct null : public parsable
{
  const char *
  pattern () const override
  {
    return R"((null))";
  }
};

struct number : public std::variant<double, int>, public parsable
{
  const char *
  pattern () const override
  {
    return R"(((-)?([\d]+)(\.[\d]+)?([eE][\+-]?[\d]+)?))";
  }
};

struct string : public parsable
{
  const char *
  pattern () const override
  {
    return R"(^"([^"\\]|\\["\\\/bfnr]|\\u[0-9a-eA-E]{4})*"$)";
  }
};
struct logic : public parsable
{
  const char *
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
  const char *
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
template <typename StringType>
struct object
    : public std::unordered_map<StringType,
                                std::variant<object<StringType>, value>>
{
};

namespace parser
{

}
} // namespace json
}; // namespace snx
