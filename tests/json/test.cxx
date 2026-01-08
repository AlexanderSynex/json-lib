#include <gtest/gtest.h>

#include "snx/json/json.h"

using namespace snx::json;

TEST (json, init)
{
  EXPECT_ANY_THROW (snx::json::json{ "" });
  auto j = json{};
  j += { "qerweqwe", 1.1 };
}
