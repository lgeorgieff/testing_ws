#include "utils/car_base_fixture.hpp"
#include "../src/bmw.hpp"
#include "../src/engine.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <cstddef>


class bmw_mock : public testing_sample::bmw {
 public:
  bmw_mock(const testing_sample::engine &engine, float max_speed, float weight, size_t vin)
      :bmw{engine, max_speed, weight, vin} {}
  virtual size_t vin() const override {
    return bmw::vin();
  }
}; // class bmw_mock

class bmw_f : public car_base_fixture {
 public:
  virtual std::unique_ptr<testing_sample::engine> create_instance(float horse_power = HORSE_POWER) const override {
    return car_base_fixture::create_instance(horse_power);
  }

  virtual std::unique_ptr<testing_sample::car> create_instance(const testing_sample::engine &engine,
      float max_speed = MAX_SPEED, float weight = WEIGHT, size_t vin = VIN) const override {
    return std::make_unique<bmw_mock>(engine, max_speed, weight, vin);
  }
}; // class bmw_f

TEST_F(bmw_f, subclass_can_be_instantiated) {
  auto bmw{create_instance(*create_instance())};
  EXPECT_TRUE(bmw);
}

TEST_F(bmw_f, vin_is_set) {
  auto four_series{create_instance(*create_instance())};
  EXPECT_EQ(four_series->vin(), VIN);
}

TEST_F(bmw_f, equals_operator_returns_correct_value) {
  auto bmw1{create_instance(*create_instance())},
    bmw2{create_instance(*create_instance(HORSE_POWER + 1), MAX_SPEED + 1, WEIGHT + 1)},
    bmw3{create_instance(*create_instance(), MAX_SPEED, WEIGHT, VIN + 1)};
  EXPECT_TRUE(dynamic_cast<testing_sample::bmw &>(*bmw1) == dynamic_cast<testing_sample::bmw &>(*bmw1));
  EXPECT_TRUE(dynamic_cast<testing_sample::bmw &>(*bmw1) == dynamic_cast<testing_sample::bmw &>(*bmw2));
  EXPECT_FALSE(dynamic_cast<testing_sample::bmw &>(*bmw1) == dynamic_cast<testing_sample::bmw &>(*bmw3));
}

TEST_F(bmw_f, unequals_operator_returns_correct_value) {
  auto bmw1{create_instance(*create_instance())},
      bmw2{create_instance(*create_instance(HORSE_POWER + 1), MAX_SPEED + 1, WEIGHT + 1)},
      bmw3{create_instance(*create_instance(), MAX_SPEED, WEIGHT, VIN + 1)};
  EXPECT_FALSE(dynamic_cast<testing_sample::bmw &>(*bmw1) != dynamic_cast<testing_sample::bmw &>(*bmw1));
  EXPECT_FALSE(dynamic_cast<testing_sample::bmw &>(*bmw1) != dynamic_cast<testing_sample::bmw &>(*bmw2));
  EXPECT_TRUE(dynamic_cast<testing_sample::bmw &>(*bmw1) != dynamic_cast<testing_sample::bmw &>(*bmw3));
}