//
// Created by Ahmed Abou Aliaa on 05.11.20.
//

#include <gtest/gtest.h>

TEST(placeholder, placeholder_test) { // NOLINT

  EXPECT_EQ(1, 0);
}

auto main(int /*argc*/, char ** /*argv*/) -> int {

  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
