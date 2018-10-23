#include "../src/four_series.hpp"
#include "../src/four_series.hpp"
#include "../src/bmw_manufacturer.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <cstddef>

TEST(bmw_manufacturer, can_be_instantiated) {
  testing_sample::bmw_manufacturer manufacturer{{}};
  SUCCEED();
}

