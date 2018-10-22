#pragma once

#include "engine_mock.hpp"
#include "car_mock.hpp"
#include "../../src/car.hpp"
#include "../../src/engine.hpp"

#include <gmock/gmock.h>

#include <cstddef>

const float HORSE_POWER{323.0F};
const float MAX_SPEED{283.0F};
const float WEIGHT{1523.321F};
const size_t VIN{1234567890};

class car_base_fixture : public ::testing::Test {
 public:
  ~car_base_fixture() { TearDown(); }
  void SetUp() {}
  void TearDown() {}

  virtual std::unique_ptr<testing_sample::engine> create_instance(float horse_power = HORSE_POWER) const {
    return std::make_unique<engine_mock>(horse_power);
  }

  virtual std::unique_ptr<testing_sample::car> create_instance(const testing_sample::engine &engine,
      float max_speed = MAX_SPEED, float weight = WEIGHT, size_t vin = VIN) const {
    return std::make_unique<car_mock>(engine, max_speed, weight);
  }
}; // class car_base_fixture
