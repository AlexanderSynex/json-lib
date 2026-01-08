#include <gtest/gtest.h>

#include "snx/json/details/types.hpp"
#include "snx/json/details/utils.hpp"

using namespace snx::json;

TEST (types, simple_string)
{
  EXPECT_TRUE (types::string{}.is_type (R"("")"));
  EXPECT_TRUE (types::string{}.is_type (R"("string")"));
  EXPECT_TRUE (types::string{}.is_type (R"("'string'")"));
  EXPECT_FALSE (types::string{}.is_type (R"('string')"));
};

TEST (types, special_strings)
{
  EXPECT_TRUE (types::string{}.is_type (R"("\"")"));
  EXPECT_TRUE (types::string{}.is_type (R"("\"")"));
  EXPECT_TRUE (types::string{}.is_type (R"("\\")"));
  EXPECT_TRUE (types::string{}.is_type (R"("\/")"));
  EXPECT_TRUE (types::string{}.is_type (R"("\b")"));
  EXPECT_TRUE (types::string{}.is_type (R"("\f")"));
  EXPECT_TRUE (types::string{}.is_type (R"("\n")"));
  EXPECT_TRUE (types::string{}.is_type (R"("\r")"));
  EXPECT_TRUE (types::string{}.is_type (R"("\uAB11")"));
  EXPECT_FALSE (types::string{}.is_type (R"("\uAQ1Q")"));
};
