#include <gtest/gtest.h>

#include "snx/json/details/types.hpp"
#include "snx/json/details/utils.hpp"

using namespace snx::json;

TEST (types, integer_number)
{
  EXPECT_TRUE (types::number{}.is_type ("1"));
  EXPECT_TRUE (types::number{}.is_type ("112"));
  EXPECT_TRUE (types::number{}.is_type ("131"));
}

TEST (types, negative_integer_number)
{
  EXPECT_TRUE (types::number{}.is_type ("-1"));
  EXPECT_TRUE (types::number{}.is_type ("-112"));
  EXPECT_TRUE (types::number{}.is_type ("-131"));
}

TEST (types, float_number)
{
  EXPECT_FALSE (types::number{}.is_type ("1."));
  EXPECT_TRUE (types::number{}.is_type ("1.1"));
  EXPECT_TRUE (types::number{}.is_type ("111.11515"));
}

TEST (types, negative_float_number)
{
  EXPECT_FALSE (types::number{}.is_type ("-1."));
  EXPECT_TRUE (types::number{}.is_type ("-1.1"));
  EXPECT_TRUE (types::number{}.is_type ("-111.11515"));
}

TEST (types, exponent_number)
{
  EXPECT_TRUE (types::number{}.is_type ("1e5"));
  EXPECT_TRUE (types::number{}.is_type ("1e+5"));
  EXPECT_TRUE (types::number{}.is_type ("1e-5"));
  EXPECT_TRUE (types::number{}.is_type ("1.151E+5"));
  EXPECT_TRUE (types::number{}.is_type ("1.1151E-5"));
}
