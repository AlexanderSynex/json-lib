#pragma once

#include "details.hpp"
#include <string_view>
namespace snx
{
namespace json
{
namespace utils
{
enum class ErrorCode
{
  NO_ERROR = 0,
  INVALID_STRUCTURE = 1,
};

template <typename Expected>
bool
is_valid_type (snx::types::string_view str)
{
  return Expected{}.is_type (str);
}

constexpr inline snx::types::string_view
trim_lead_ws (snx::types::string_view str) noexcept
{
  str.remove_prefix (std::min (str.find_first_not_of (" "), str.size ()));
  return str;
}

constexpr inline snx::types::string_view
trim_trail_ws (snx::types::string_view str) noexcept
{
  if (str.find_last_not_of (" ") == snx::types::string_view::npos)
    {
      return {};
    }
  str.remove_suffix (str.size () - (str.find_last_not_of (" ") + 1));
  return str;
}

constexpr inline snx::types::string_view
trim_ws (snx::types::string_view str) noexcept
{
  return trim_lead_ws (trim_trail_ws (str));
}

inline bool
validate (snx::types::string_view dump, ErrorCode &ec)
{
  ec = ErrorCode::NO_ERROR;
  auto trimmed = trim_ws (dump);
  if (not trimmed.starts_with ('{') or not trimmed.ends_with ('}'))
    {
      ec = ErrorCode::INVALID_STRUCTURE;
      return false;
    }

  if (trimmed.size () < 2)
    {
      ec = ErrorCode::INVALID_STRUCTURE;
      return false;
    }

  return true;
}
} // namespace utils

} // namespace json
} // namespace snx
