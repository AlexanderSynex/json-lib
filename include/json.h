#pragma once

#include <unordered_map>
#include <variant>
namespace snx {
namespace json {

    struct null { };

    struct number : std::variant<double, int> { };

    /// An array is an ordered collection of values.
    /// An array begins with [left bracket and ends with ]right bracket.
    /// Values are separated by ,comma.
    struct array { };

    struct string { };

    /// An object is an unordered set of name/value pairs.
    /// An object begins with {left brace and ends with }right brace.
    /// Each name is followed by :colon and the name/value pairs are separated by
    /// ,comma.
    template <typename StringType>
    struct object
        : std::unordered_map<StringType,
              std::variant<number, bool, string, array,
                  object<StringType>, null>> { };
} // namespace json
}; // namespace snx
