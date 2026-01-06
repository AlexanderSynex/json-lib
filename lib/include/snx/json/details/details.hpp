#pragma once

#include <optional>
#include <string>
#include <string_view>
namespace snx
{
namespace types
{
using string = std::string;
using string_view = std::string_view;

template <typename ValueType> using optional = std::optional<ValueType>;

} // namespace types
} // namespace snx
