#include <gtest/gtest.h>

#include "snx/json/details/utils.hpp"

using namespace snx::json::utils;

TEST (utils, trim_lead_ws)
{
  EXPECT_EQ (trim_lead_ws (""), "");
  EXPECT_EQ (trim_lead_ws (" hello"), "hello");
  EXPECT_EQ (trim_lead_ws ("     hello"), "hello");
  EXPECT_EQ (trim_lead_ws ("     hello  "), "hello  ");
}

TEST (utils, trim_trail_ws)
{
  EXPECT_EQ (trim_trail_ws (""), "");
  EXPECT_EQ (trim_trail_ws (" hello"), " hello");
  EXPECT_EQ (trim_trail_ws ("hello     "), "hello");
  EXPECT_EQ (trim_trail_ws ("     hello  "), "     hello");
}

TEST (utils, trim_ws)
{
  EXPECT_EQ (trim_ws (""), "");
  EXPECT_EQ (trim_ws (" hello"), "hello");
  EXPECT_EQ (trim_ws ("hello     "), "hello");
  EXPECT_EQ (trim_ws ("     hello  "), "hello");
}
