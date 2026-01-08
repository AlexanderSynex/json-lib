#include <gtest/gtest.h>

#include "snx/json/details/utils.hpp"

using namespace snx::json::utils;

TEST (validation, empty)
{
  auto ec = ErrorCode::NO_ERROR;
  EXPECT_FALSE (validate ("", ec));
  EXPECT_EQ (ec, ErrorCode::INVALID_STRUCTURE);

  EXPECT_FALSE (validate ("{", ec));
  EXPECT_EQ (ec, ErrorCode::INVALID_STRUCTURE);

  EXPECT_TRUE (validate ("{}", ec));
  EXPECT_EQ (ec, ErrorCode::NO_ERROR);
}
