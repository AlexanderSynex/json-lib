#include <gtest/gtest.h>

#include "snx/json/details/types.hpp"
#include "snx/json/details/utils.hpp"

using namespace snx::json;

TEST (types, null_value)
{
  EXPECT_TRUE (types::null{}.is_type ("null"));
  EXPECT_FALSE (types::null{}.is_type (R"(nUll)"));
  EXPECT_FALSE (types::null{}.is_type (R"(nUlL)"));
  EXPECT_FALSE (types::null{}.is_type (R"("null")"));
};
