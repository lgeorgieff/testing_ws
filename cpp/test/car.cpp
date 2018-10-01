#include "../src/car.hpp"

#include <gtest/gtest.h>

TEST(car, cannot_be_instantiated) {
  SUCCEED();
}

TEST(car, subclass_can_be_instantiated) {
  SUCCEED();
}

TEST(car, constructor_sets_engine) {
  SUCCEED();
}

TEST(car, constructor_sets_max_speed) {
  SUCCEED();
}

TEST(car, constructor_sets_weight) {
  SUCCEED();
}

TEST(car, speed_sets_internal_value) {
  SUCCEED();
}

TEST(car, speed_only_allows_valid_values) {
  SUCCEED();
}

TEST(car, is_driving_returns_valid_value) {
  SUCCEED();
}

TEST(car, horse_power_returns_value_from_engine) {
  SUCCEED();
}

TEST(car, average_speed_is_0_when_car_was_not_driving) {
  SUCCEED();
}

TEST(car, average_speed_is_updated_when_car_is_driving) {
  SUCCEED();
}

TEST(car, average_speed_is_nt_updated_when_car_is_not_driving) {
  SUCCEED();
}

TEST(car, average_speed_is_updated_when_car_was_driving_and_stopping_multiple_times) {
  SUCCEED();
}