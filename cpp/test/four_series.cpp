#include "utils/car_base_fixture.hpp"
#include "../src/four_series.hpp"
#include "../src/engine.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <cstddef>

class four_series_mock : public testing_sample::four_series {
 public:
  four_series_mock(const testing_sample::engine &engine, float max_speed, float weight, size_t vin)
      :four_series{engine, max_speed, weight, vin} {}
}; // class four_series_mock

class four_series_f : public car_base_fixture {
 public:
  virtual std::unique_ptr<testing_sample::engine> create_instance(float horse_power = HORSE_POWER) const override {
    return car_base_fixture::create_instance(horse_power);
  }

  virtual std::unique_ptr<testing_sample::car> create_instance(const testing_sample::engine &engine,
                                                               float max_speed = MAX_SPEED,
                                                               float weight = WEIGHT, size_t vin = VIN) const override {
    return std::make_unique<four_series_mock>(engine, max_speed, weight, vin);
  }
}; // class four_series_f

TEST_F(four_series_f, subclass_can_be_instantiated) {
  auto four_series{create_instance(*create_instance())};
  EXPECT_TRUE(four_series);
}

TEST_F(four_series_f, vin_is_set) {
  auto four_series{create_instance(*create_instance())};
  EXPECT_EQ(four_series->vin(), VIN);
}